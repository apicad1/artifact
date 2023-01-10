This file covers aspects of our original hardware and software testing environments, which can be considered as a reference for hardware and software requirements.

# Hardware testing environments

CPU: 11th Gen Intel Core i7-11700 @ 2.50GHz

Memory: 48 GB DDR4 3200MHz

Storage: 500 GB SSD

# Software testing environments

OS: Ubuntu 20.04 LTS (x86_64)

package dependencies:

  - Rust (https://rustup.rs)

    For sub-dependencies, see `Cargo.toml` in the source directories.

 - Clang 12.0.0

- wllvm (https://github.com/travitch/whole-program-llvm)

- Python3 environment (developed on python 3.8)

  In addition to [the standard library](https://docs.python.org/3.8/library/index.html), it also depends on requests, lxml, and hanlp.
  
  - Hanlp (https://hanlp.hankcs.com/docs/)
  
    Pretrained models for original evaluation:
  
    ud_ontonotes_tok_pos_lem_fea_ner_srl_dep_sdp_con_xlm_base_20210602_211620
  
    xlm-roberta-base_20210706_125502
    
    eos_ud_ctb_mul_20201222_133543

Optional:

- Docker

  Build a Docker image from the Dockerfile for ubuntu:20.04 (tested on Docker version 20.10.21, build baeda1f).

