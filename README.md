This artifact provides the guidance and the information needed to support the reusability and availability of the experimental results reported in the paper "APICAD: Augmenting API Misuse Detection through Specifications from Code and Documents". We hope this artifact can help future research to further tackle generic API misuses of C/C++.

# What's inside this artifact:

- "basic_example" directory

  A pre-built LLVM bitcode file for showing how to use the prototype.

- "docker" directory

  The Dockerfile to build a docker image for this artifact.

- "evaluation" directory
  - "database" directory

    In this directory, we provide the pre-built files for the whole APIMU4C benchmark so that we can directly run APICAD to replicate the experimental results. Besides, in order to facilitate reproduction, we also provide instructions to build the benchmark and real-world projects.

    See more in the inside [README](./evaluation/database/README.md).

  - "evaluation_results" directory
  
    This directory contains the original evaluation results of the study.
    
    See more in the inside [README](./evaluation/ori_evaluation_results/README.md).
  
- "src" directory

  The prototype of APICAD. To better support the replication of our results, we retained the analyzed documents so that we could directly run APICAD with many analyzed doc-based specifications enabled.

# Installation

(The process takes about 15 mins, which can be influenced by the network status)

This artifact provides two ways to build it:

1) Build it on Ubuntu 20.04 LTS (x86_64) with shell commands.
2) Build a docker image from the Dockerfile for it.

Please see details in [INSTALL.md](./INSTALL.md).

# Basic usage

APICAD is for augmenting detecting three common types (return check, argument check, and causal calls) of API misuse bugs through specifications from code and documents.

In APICAD, there are two parallel workflows. The first is for analyzing code, while the second is for analyzing documents. Workflow 1 is indispensable since we at least need to analyze the code to be detected.

## Workflow 1

In workflow 1, we can run with 2 steps to generate code-based spec:

1. build (and generate .bc files):

   ```sh
   # compile the source code
   $ apicad build [config|make|cmake...]
   
   # (Optional) generate .bc files for the complied projects
   # If this operation is not performed in advance,
   # apicad will attempt to automatically do this in `apicad analyze`
   $ apicad generate-bc [-obj --bcdir=...]
   # Or you can generate by yourself with `-g`
   $ clang -c -emit-llvm source.c -g -o source.bc
   ```

2. generate symbolic traces and features:

   ```sh
   # generate symbolic traces and features for all functions
   # note: analyze for a specific funciton by "--target-fn=..."
   $ apicad analyze [--bcdir=...] [--outdir=...]
   ```

   There are other options such as `--target`, `--bc` etc, take `--help` to see their details.

Then you can detect API misuse bugs:

```sh
$ apicad detect [--type retval|arg.pre|arg.post|causality] [--target func_name]
```

## Workflow 2

For more accurate detection, APICAD can give play to both code-based spec and doc-based spec rather than taking a single source.

To enable doc-based spec for detection, you need to collect documents and then use the document analyzer to generate doc-based spec.

1. collect documents from the website

   ```sh
   # Now only support to handle these three documents
   $ apicad doc-collect [--target glibc|linux|openssl]
   ```

2. analyze documents to generate doc-based spec

   ```sh
   $ apicad doc-analyze [--semantic-type return|args|causality]
   ```

Then you can detect API misuse bugs with doc-enhanced spec by adding the option `--enable-doc`:

```sh
$ apicad detect --enable-doc [--type retval|arg.pre|arg.post|causality] [--target func_name]
```

## One running example

To conveniently show the basic functionality of APICAD, we prepared a pre-built LLVM bitcode file of libcurl in the "basic_example" directory.

Therefore, we can go to the directory and then directly run

```bash
$ apicad analyze --target SSL_get_ex_data EVP_MD_CTX_new
```

to perform the analysis for code. The output of APICAD will show the analyzing status.

After that, use `apicad detect` to get reports from the detection with only code-based specifications.

Running `apicad detect --enable-doc` to perform the detection with doc-based specifications enabled.

# Evaluation Guideline

Please refer to [EVALUATION.md](./evaluation/EVALUATION.md).

