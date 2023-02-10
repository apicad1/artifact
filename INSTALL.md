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
  # Please ensure that `apicad` is executable.
  # If not, use `chmod +x apicad` to enable the permission.
  $ make # about 2 mins
  $ make install
  ```

# Build Artifact from the Dockerfile

> **If the host OS is Windows**:
>
> There are files with relatively long path prefixes and the default length of a path on Windows is up to 260 characters, so before we build the docker image, we should 1) Put the artifact in a position with a shorter path prefix length. or 2) Remove the default path length limitation (after Windows 10, version 1607). See more details at [link](https://learn.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation#enable-long-paths-in-windows-10-version-1607-and-later). or 3) Update the Docker to date.
>
> Note that the last option is an empirical solution. When we put the artifact at a long path on Win 10, we got "Access is denied" with Docker Desktop 3.0.4 [Docker Engine v20.10.2], but built successfully with Docker Desktop version 4.15.0 [Docker Engine v20.10.21].
>
> Besides, we need also to notice that the line ending is different between DOS and Unix. So if you encounter an error like "/usr/bin/env: 'xxx \r': No such file or directory", please use `dos2unix` (download it via `apt-get install dos2unix`) to convert the file format, e.g., `dos2unix /path/to/file`.

```bash
$ docker build -t apicad_artifact -f docker/Dockerfile . # about 12 mins
$ docker run -it apicad_artifact
/apicad$ cd src
# Please ensure that `apicad` is executable.
# If not, use `chmod +x apicad` to enable the permission.
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

The first command is to analyze the bitcode file(s) for `SSL_get_ex_data` and `EVP_MD_CTX_new`. The expected response to the first command is just like the following:

```
root@8b9ac2728c3b:/apicad/basic_example# apicad analyze --target SSL_get_ex_data EVP_MD_CTX_new
[2023-02-10 01:31:54] INFO(Analyzer): === Starting to analyze ===
[2023-02-10 01:31:54] INFO(Analyzer): === Running analyzer on /apicad/basic_example/bc-files/libcurl.so_0.bc... ===
[2023-02-10 01:31:54.137273300 +00:00] Loading byte code file and creating context...
[2023-02-10 01:31:54.810447800 +00:00] Generating call graph...
[2023-02-10 01:31:54.820693400 +00:00] Finding relevant call edges...
[2023-02-10 01:31:54.821192900 +00:00] 6 call edges have been found, generating slices...
[2023-02-10 01:31:54.825101600 +00:00] 6 slices have been generated, dumping slices to json...
[2023-02-10 01:31:54.826383 +00:00] Running symbolic execution on 6 slices for 2 functions
[2023-02-10 01:31:59.210805700 +00:00] Finished symbolic execution; MetaData { proper_trace_count: 203, path_unsat_trace_count: 0, branch_explored_trace_count: 0, duplicate_trace_count: 0, no_target_trace_count: 0, exceeding_length_trace_count: 0, timeout_trace_count: 0, unreachable_trace_count: 0, explored_trace_count: 203 }
[2023-02-10 01:31:59.210881300 +00:00] Extracting features...
[2023-02-10 01:32:01.450989300 +00:00] Feature extractor finished
[2023-02-10 01:32:01] INFO(Analyzer): === Finished ===
```

The second command is to detect the misuse of `SSL_get_ex_data` and `EVP_MD_CTX_new` by only enabling the code-based specification. The corresponding response is just like the following:

```
root@8b9ac2728c3b:/apicad/basic_example# apicad detect
[2023-02-10 01:32:03] INFO(detection): Detecting for 2 functions
[2023-02-10 01:32:03] INFO(detector): Processing EVP_MD_CTX_new
[2023-02-10 01:32:03] INFO(detector): Processing SSL_get_ex_data
[2023-02-10 01:32:03] ERROR(BUGREPORT): EVP_MD_CTX_new:
        Location:/home/test/api_misuse/evaluation/real-world/curl-src/lib/sha256.c:87:22
        TYPE: retval. feature: {'check': {'check_cond': '', 'checked': False, 'compared_with_const': 0, 'compared_with_non_const': False, 'indir_checked': False}, 'ctx': {'derefed_read': False, 'derefed_write': False, 'indir_returned': False, 'returned': False, 'stored_not_local': True, 'used_in_bin': False, 'used_in_call': True}}
        Violation: Lacking proper check for the return value.

[2023-02-10 01:32:03] INFO(BUGREPORT): Total reports: 1
[2023-02-10 01:32:03] INFO(detection): Have dumpped results to /apicad/basic_example/cad-output/bugreport.txt ###
```

The last command gives play to both code-based spec and doc-based spec for detection:

```
root@8b9ac2728c3b:/apicad/basic_example# apicad detect --enable-doc
[2023-02-10 01:32:05] INFO(detection): Detecting for 2 functions
[2023-02-10 01:32:05] INFO(detector): Processing EVP_MD_CTX_new
[2023-02-10 01:32:05] INFO(detector): Processing SSL_get_ex_data
[2023-02-10 01:32:05] ERROR(BUGREPORT): EVP_MD_CTX_new:
        Location:/home/test/api_misuse/evaluation/real-world/curl-src/lib/sha256.c:87:22
        TYPE: retval. feature: {'check': {'check_cond': '', 'checked': False, 'compared_with_const': 0, 'compared_with_non_const': False, 'indir_checked': False}, 'ctx': {'derefed_read': False, 'derefed_write': False, 'indir_returned': False, 'returned': False, 'stored_not_local': True, 'used_in_bin': False, 'used_in_call': True}}
        Violation: Lacking proper check for the return value.

[2023-02-10 01:32:05] ERROR(BUGREPORT): SSL_get_ex_data:
        Location:/home/test/api_misuse/evaluation/real-world/curl-src/lib/vtls/openssl.c:2497:31
        TYPE: retval. feature: {'check': {'check_cond': '', 'checked': False, 'compared_with_const': 0, 'compared_with_non_const': False, 'indir_checked': False}, 'ctx': {'derefed_read': True, 'derefed_write': False, 'indir_returned': False, 'returned': False, 'stored_not_local': False, 'used_in_bin': False, 'used_in_call': True}}
        Violation: Dereferenced read/write the return value without check.

        TYPE: retval. feature: {'check': {'check_cond': '', 'checked': False, 'compared_with_const': 0, 'compared_with_non_const': False, 'indir_checked': False}, 'ctx': {'derefed_read': True, 'derefed_write': False, 'indir_returned': False, 'returned': False, 'stored_not_local': False, 'used_in_bin': False, 'used_in_call': False}}
        Violation: Dereferenced read/write the return value without check.


[2023-02-10 01:32:05] ERROR(BUGREPORT): SSL_get_ex_data:
        Location:/home/test/api_misuse/evaluation/real-world/curl-src/lib/vtls/openssl.c:2500:36
        TYPE: retval. feature: {'check': {'check_cond': '', 'checked': False, 'compared_with_const': 0, 'compared_with_non_const': False, 'indir_checked': False}, 'ctx': {'derefed_read': False, 'derefed_write': False, 'indir_returned': False, 'returned': False, 'stored_not_local': False, 'used_in_bin': True, 'used_in_call': False}}
        Violation: Lacking proper check for the return value.

[2023-02-10 01:32:05] INFO(BUGREPORT): Total reports: 3
[2023-02-10 01:32:05] INFO(detection): Have dumpped results to /apicad/basic_example/cad-output/bugreport.txt ###
```

# Note

When the first time analyzing documents using the instruction below, the pre-trained model provided by Hanlp needs to be downloaded.

```bash
$ apicad doc-analyze
```

The model size is about 1.1GB, the downloading time is about 5 mins.

In fact, this would not influence the mostly evaluation because we retain the analyzed specification from documents. But if we want to reproduce the evaluation results for the performance of document analysis, this step must be done.

