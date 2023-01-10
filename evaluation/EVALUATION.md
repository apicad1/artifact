The study leverages APIMU4C Single-File-Case benchmark (Section III-B), APIMU4C Project-Case benchmark (Section III-C), and four well-known open source projects (Section III-D) including Curl (master c40914db), Httpd 2.4.51, OpenSSL (master 0299094c) and Linux kernel 5.15 for evaluation. Section III-E also has the evaluation for the performance of code and doc analysis. The original evaluation results are placed in `evaluation_results` directory.

To do the evaluation, we need to build our targets to LLVM bitcode files. In `database` directory, we provide the pre-built files for the whole APIMU4C benchmark (APIMU4C-project-case and APIMU4C-single-file-case) so that we can directly run APICAD. Besides, in order to facilitate reproduction, we also provide instructions to build the benchmark and real-world projects. See more details in [README](./database/README.md).

In the following content, we assume that the corresponding projects have been built, that is, we should have bitcode files for evaluation.

# Evaluation on APIMU4C Single-File-Case

Because we have retained the generated files, we can go to the folder of the APIMU4C Single-File-Case (In the docker image, the path is `/apicad/database/APIMU4C-single-file-case`), and then directly run the command below to generate results for the whole benchmark:

```bash
APIMU4C-single-file-case$ apicad evaluate --direct-detect
```

Or, we can re-build the benchmark and generate results for it:

```bash
APIMU4C-single-file-case$ apicad evaluate
```

Besides, to generate results for a specific part of the benchmark:

```bash
APIMU4C-single-file-case$ cd CWE252_Unchecked_Return_Value
APIMU4C-single-file-case/CWE252_Unchecked_Return_Value$ apicad evaluate [--direct-detect]
```

The output files will be generated. For now, `detect_reports.txt` records the bug reported by APICAD. This evaluation corresponds to Section III-B of the paper. Due to there being multiple potential tags, the results need to be analyzed manually according to the files of the benchmark.

We put the original validated results in `evaluation_results/apimu4c-single-file`, so after getting the outputs, we can make validation by comparing them.

# Evaluation on APIMU4C Project-Case

This evaluation corresponds to Section III-C of the paper. Like APIMU4C Single-File-Case, we also retain the analyzed features for this benchmark. Therefore, we can directly go to the directory of the project and perform the commands to acquire the evaluation results.

Let us take Curl as an example, we can go to the directory `database/APIMU4C-project-case/curl` (in the docker image, the path is `apicad/database/APIMU4C-project-case/curl`) and then run the following commands to get the evaluation results in Table V.

```bash
$ apicad detect --only [--enable-doc] [--threshold 0.5|0.8]
```

We can certainly re-analyze the project and then do the detection on newly analyzed data:

```bash
$ apicad evaluate --project curl # [httpd|openssl]
$ apicad detect --only [--enable-doc] [--threshold 0.5|0.8]
```

We put the original validated results as well as the ground truth at `evaluation_results/apimu4c-project-case`, so after getting the outputs, it is convenient to do validation by making a comparison between them.

# Evaluation on real-world

This part aims to evaluate the impact and practicality of APICAD.

After building the projects, we can run APICAD on the built bitcode files for the APIs used by real-world projects:

```bash
# Perform the analysis for the target API
$ apicad analyze --target name
# Leverage different capabilities provided by APICAD according to actual demand to generate bug reports for it
$ apicad detect [--enable-doc|...]
```

We manually validated the raw reports and reported many bugs to the maintainers. The information on confirmed bugs and the validation data for APISAN are put in `evaluation_results/real-world/effectiveness`, which corresponds to Section III-D.

The evaluation results of Section III-E-1) are obtained by running APICAD for analyzing the whole project of Curl, Httpd, and OpenSSL as well as a heavily used API (`kzalloc`) of Linux.

# Document analysis

For extracting usage semantics from documents, we should run:

```bash
$ apicad doc-analyze
```

Then the time consumption will be outputted, which corresponds to Section III-E-2). Note that the first time we need to load the pre-trained model from the website, but it is a one-time job, so we assume the model has been loaded by default.

Evaluating the quality of constructed specifications is a manual process, we provide our previous manual validation results for the specifications of 600 randomly selected functions, and put them in the `evaluation_results/doc` directory.

