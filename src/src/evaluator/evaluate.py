#!/usr/bin/env python3
import os, re, logging
from ..lib import utils

# Note: This is only for evaluating APIMU4C benchmark.

logger = logging.getLogger(utils.color_str(f"EVALUATION", 'yellow'))


def setup_parser(subparsers):
    parser = subparsers.add_parser("evaluate", help="evaluate the single files in APIMU4C")
    parser.add_argument('--outdir', '-outdir', type=str, default=None,
                        help='The directory where to save output, default is codebase/')
    parser.add_argument('--direct-detect', action='store_true', help='Direct detect(Facilitate repeated evaluation)')
    parser.add_argument('--threshold', type=float, default=None, help="The threshold of frequency-based specification.")
    parser.add_argument('--collect-loc', action='store_true', help='Collect locations from bugreport.txt')
    parser.add_argument('--project-case', '-project', type=str, default=None,
                        help='Automatically analyze the API in project-case benchmark(curl/httpd/openssl).')


class single_Evaluation:
    def __init__(self, file_paths, output_dir=None):
        self.file_paths = file_paths
        self.output_dir = output_dir

    # Extract the real bug position in each file by finding "FLAW:"
    # Note: Some of them can not be extracted automatically such as CWE401.
    # In fact, this is NOW only helpful for CWE252/253.
    def create_baseline(self):
        base_dirs = []
        baseline = []
        for file in self.file_paths:
            base_dirs.append(os.path.dirname(file))
            with open(file, "r") as f:
                lines = f.readlines()
                for index, line in enumerate(lines):
                    if "FLAW:" in line:
                        basename = os.path.basename(file)
                        if basename[:6] == "CWE252":
                            baseline.append(file + f":{index+2}")  # index+2 = the position of buggy code?
                        elif basename[:6] == "CWE253":
                            baseline.append(file + f":{index+3}")  # index+3 = the position of buggy code?
                        else:
                            baseline.append(file + f":{index}")  # default...

        if self.output_dir:
            with open(os.path.join(self.output_dir, "baselines.txt"), "w") as f:
                f.write(f"Total: {len(baseline)}\n")
                for line in baseline:
                    f.write(line + "\n")
        return base_dirs, baseline

    def get_detect_reports(self, base_dirs, direct_detect, threshold = None):
        results = []
        for dir_path in base_dirs:
            os.chdir(dir_path)
            if not direct_detect:
                if os.system("apicad build make") != 0:
                    raise Exception(utils.color_str("Failure during running apicad build make"))
                if os.path.exists("./cad-output") and os.system("rm -r ./cad-output") != 0:
                    raise Exception(utils.color_str("Failure during cleaning ./cad-output"))
                if os.system("apicad analyze") != 0:
                    raise Exception(utils.color_str("Failure during running apicad analyze"))
            detect_cmd = "apicad detect"
            if threshold != None and type(threshold) == float:
                detect_cmd += " --threshold " + str(threshold)
            if os.system(detect_cmd) != 0:
                raise Exception(utils.color_str("Failure during running apicad detect"))
            with open(os.path.join(dir_path, "cad-output/bugreport.txt"), 'r') as f:
                lines = f.readlines()
                for line in lines:
                    if "Location:" in line:
                        results.append(re.split(":\d+$", line.split("Location:")[1])[0])

        if self.output_dir:
            with open(os.path.join(self.output_dir, "detect_reports.txt"), "w") as f:
                f.write(f"Total: {len(results)}\n")
                for line in results:
                    f.write(line + "\n")
        return results

    def generate_evaluation_results(self, baseline, detect_reports):
        total_baseline = len(baseline)
        total_reports = len(detect_reports)
        TP_results = []
        FN_results = []
        FP_results = []
        tp = 0
        for item in baseline:
            if item in detect_reports:
                tp += 1
                TP_results.append(item)
            else:
                FN_results.append(item)
        fp = total_reports - tp
        fn = total_baseline - tp

        for item in detect_reports:
            if item not in baseline:
                FP_results.append(item)

        print(f"Total samples: {total_baseline}, total_reports: {total_reports}\n \
            TP: {tp}, FP: {fp}, FN: {fn}")

        if self.output_dir:
            with open(os.path.join(self.output_dir, "evaluation_results.txt"), "w") as f:
                f.write(f"Total samples: {total_baseline}, Total_reports: {total_reports}\n \
            TP: {tp}, FP: {fp}, FN: {fn}\n")
                f.write("***** TP *****\n")
                for item in TP_results:
                    f.write(item + "\n")
                f.write("***** FN *****\n")
                for item in FN_results:
                    f.write(item + "\n")
                f.write("***** FP *****\n")
                for item in FP_results:
                    f.write(item + "\n")


def evaluate(args):
    if not args.collect_loc:
        # evaluate_single
        logger.info("### acquiring .c files to evaluate ###")
        file_paths = utils.files_to_evaluate(args)

        evaluation = single_Evaluation(file_paths, args.outdir)

        logger.info("### creating baseline for evaluation ###")
        base_dirs, baseline = evaluation.create_baseline()

        logger.info("### detecting each single file for evaluation ###")
        detect_reports = evaluation.get_detect_reports(base_dirs, args.direct_detect, args.threshold)

        logger.info("### generating evaluation results ###")
        evaluation.generate_evaluation_results(baseline, detect_reports)
    else:
        # Collect locations from normal output.
        results = []
        with open(os.path.join(args.outdir, "cad-output/bugreport.txt"), 'r') as f:
            lines = f.readlines()
            for line in lines:
                if "Location:" in line:
                    results.append(re.split(":\d+$", line.split("Location:")[1])[0])

        with open(os.path.join(args.outdir, "detect_reports.txt"), "w") as f:
            f.write(f"Total: {len(results)}\n")
            for line in results:
                f.write(line + "\n")


def evaluate_project(project):
    target_APIs =  {
        "httpd": ['BIO_new_file', 'X509_get_ext_d2i', 'BIO_new', 'apr_thread_mutex_lock', 'ap_pcfg_openfile',
            'DH_new', 'X509_STORE_CTX_new', 'apr_sockaddr_info_get', 'BN_bn2dec', 'ssl_init_ctx_verify'],
        "curl": ['BIO_new', 'BIO_ctrl', 'SSL_CTX_use_PrivateKey', 'Curl_ssl_sessionid_lock', 'SSL_get_peer_cert_chain',
            'Curl_urldecode', 'mbedtls_version_from_curl', 'x509_crt_parse_file', 'ssl_write', 'Curl_timeleft',
            'mbedtls_pk_parse_keyfile'],
        "openssl": ['CRYPTO_realloc', 'ASN1_TIME_diff', 'sk_SSL_CIPHER_new_null', 'EC_GROUP_dup',
            'BN_CTX_get', 'X509_NAME_ENTRY_new', 'i2a_ASN1_OBJECT', 'OBJ_txt2obj', 'OBJ_dup', 'i2s_ASN1_INTEGER',
            'X509_STORE_CTX_new', 'ASN1_GENERALIZEDTIME_set_string', 'bn_wexpand', 'EVP_MD_CTX_new', 'EVP_CipherInit_ex',
            'CRYPTO_THREAD_lock_new', 'BUF_MEM_grow_clean', 'ASN1_object_size', 'ssl_generate_pkey', 'PACKET_buf_init',
            'ASN1_STRING_to_UTF8']
    }
    if project not in target_APIs:
        logger.error("No proper project found. Please choose one from curl/httpd/openssl.")
    run_cmd = "apicad analyze --target "
    for target_api in target_APIs[project]:
        run_cmd += target_api + " "
    if os.system(run_cmd) != 0:
        import signal
        logger.error(utils.color_str(f"Fail to run apicad analyze or Self-Terminated\n"))
        os.killpg(os.getpid(), signal.SIGKILL)
    return


def main(args):
    if args.outdir == None:
        args.outdir = os.path.join(args.codebase)
    else:
        args.outdir = os.path.abspath(args.outdir)
    if utils.mkdir(args.outdir) == 0:
        if args.project_case == None:
            evaluate(args)
        else:
            evaluate_project(args.project_case)
    return
