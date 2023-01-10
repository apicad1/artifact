After obtaining and decompressing the artifact, we have two ways to build it. The first one is for a machine with Ubuntu 20.04 LTS (x86_64), and the other one is to build a docker image for it.

> The estimated time is recorded based on our previous time consumption. In fact, it is mainly influenced by the network status because this process requires downloading many resources.

# Build Artifact on Ubuntu 20.04 LTS (x86_64)

- Prerequisites
  - Rust (https://rustup.rs)

  - Clang-12, LLVM, wllvm (https://github.com/travitch/whole-program-llvm)

  - Python3 environment (developed on python 3.8)

    In addition to [the standard library](https://docs.python.org/3.8/library/index.html), it also depends on requests, lxml, and hanlp.

    - Hanlp (https://hanlp.hankcs.com/docs/)

- Install prerequisites

  ```bash
  $ apt-get -y install clang-12 python3 python3-pip curl # about 4 mins
  $ ln -s /usr/bin/clang++-12 /usr/bin/clang++ && \
  	ln -s /usr/bin/clang-12 /usr/bin/clang && \
  	ln -s /usr/bin/clang-cpp-12 /usr/bin/clang-cpp && \
  	ln -s /usr/bin/llvm-link-12 /usr/bin/llvm-link && \
  	ln -s /usr/bin/llvm-ar-12 /usr/bin/llvm-ar
  $ pip3 install --upgrade wllvm requests lxml hanlp # about 5 mins
  $ curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh # about 1 min
  ```

- Install APICAD (In the "./src" directory)

  ```bash
  $ make # about 2 mins
  $ make install
  ```

# Build Artifact from the Dockerfile

```bash
$ docker build -t apicad_artifact -f docker/Dockerfile . # about 12 mins
$ docker run -it apicad_artifact
/apicad$ cd src
/apicad/src/$ make # about 2 mins
/apicad/src/$ make install
```

# Test the installation

Go to "./basic_example" (In the docker image, the path is `/apicad/basic_example`) and then run the commands below to test the basic functionality of APICAD:

```bash
$ apicad analyze --target SSL_get_ex_data EVP_MD_CTX_new
$ apicad detect
$ apicad detect --enable-doc
```

# Note

When the first time analyzing documents using the instruction below, the pre-trained model provided by Hanlp needs to be downloaded.

```bash
$ apicad doc-analyze
```

The model size is about 1.1GB, the downloading time is about 5 mins.

In fact, this would not influence the mostly evaluation because we retain the analyzed specification from documents. But if we want to reproduce the evaluation results for the performance of document analysis, this step must be done.

