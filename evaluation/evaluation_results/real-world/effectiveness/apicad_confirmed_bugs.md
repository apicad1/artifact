# Curl

| related API     | location                                                     | link                         |
| --------------- | ------------------------------------------------------------ | ---------------------------- |
| BIO_new         | lib/vtls/openssl.c:3565<br/>lib/vtls/openssl.c:3836          | https://github.com/pull/8078 |
| BIO_new_mem_buf | lib/vtls/openssl.c:3901                                      | https://github.com/pull/8233 |
| curl_easy_init  | tool_operate.c:2392 4                                        | https://github.com/pull/9114 |
| curl_url        | lib/url.c:2396                                               | https://github.com/pull/7917 |
| EVP_MD_CTX_new  | lib/sha256.c:87                                              | https://github.com/pull/8133 |
| SSL_get_ex_data | lib/vtls/openssl.c:2497<br/>lib/vtls/openssl.c:2500          | https://github.com/pull/8268 |
| SSL_set_ex_data | lib/vtls/openssl.c:4503<br/>lib/vtls/openssl.c:4504<br/>lib/vtls/openssl.c:4505<br/>lib/vtls/openssl.c:4507 | https://github.com/pull/8268 |

# Httpd

| related  API          | location                                                     | link                                                         |
| --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| apr_sockaddr_info_get | server/listen.c:689<br/>modules/proxy/mod_proxy_ftp.c:1606<br/>modules/proxy/mod_proxy_ftp.c:1563 | https://bz.apache.org/bugzilla/show_bug.cgi?id=66135<br/>https://bz.apache.org/bugzilla/show_bug.cgi?id=66136 |
| BIO_new               | modules/ssl/ssl_engine_vars.c:1086<br/>modules/ssl/ssl_util_ocsp.c:38<br/>modules/ssl/ssl_util_ocsp.c:361<br/>modules/ssl/ssl_engine_io.c:2195<br/>modules/ssl/ssl_engine_io.c:2230 | https://bz.apache.org/bugzilla/show_bug.cgi?id=65717<br/>https://bz.apache.org/bugzilla/show_bug.cgi?id=65912 |
| BN_bn2dec             | modules/ssl/ssl_engine_vars.c:777                            | https://bz.apache.org/bugzilla/show_bug.cgi?id=66137         |

# OpenSSL

| related  API                  | location                                                     | link                                                         |
| ----------------------------- | :----------------------------------------------------------- | ------------------------------------------------------------ |
| ASN1_BIT_STRING_new           | test/ocspapitest.c:78                                        | https://github.com/openssl/openssl/pull/18774                |
| ASN1_INTEGER_new              | test/ocspapitest.c:79                                        | https://github.com/openssl/openssl/pull/18774                |
| BIO_new                       | crypto/x509/t_x509.c:471  crypto/cmp/cmp_vfy.c:36 apps/lib/apps.c:301  apps/s_client.c:1665 apps/s_client.c:2087  apps/s_client.c:2152 apps/s_client.c:2200  apps/s_client.c:2227 apps/s_client.c:2321  apps/s_client.c:2481 apps/s_client.c:2521  apps/s_client.c:2579 2 # apps/s_server.c:1816 apps/s_server.c:2413  apps/s_server.c:3039 | https://github.com/openssl/openssl/pull/17175  https://github.com/openssl/openssl/pull/17421 |
| BIO_new_dgram                 | apps/s_client.c:2034 3                                       | https://github.com/openssl/openssl/pull/17421                |
| BIO_new_file                  | apps/s_client.c:1140  apps/s_server.c:1395                   | https://github.com/openssl/openssl/pull/17820                |
| BIO_new_fp                    | apps/lib/apps.c:2879                                         | https://github.com/openssl/openssl/pull/19445                |
| BIO_new_socket                | apps/s_client.c:2082                                         | https://github.com/openssl/openssl/pull/17421                |
| BN_CTX_get                    | providers/implementations/keymgmt/ec_kmgmt.c:161 providers/implementations/keymgmt/ec_kmgmt.c:163 | https://github.com/openssl/openssl/pull/19905                |
| BN_dup                        | test/testutil/tests.c:435 crypto/rsa/rsa_lib.c:1248          | https://github.com/openssl/openssl/pull/16948                |
| BN_new                        | test/testutil/tests.c:420  test/testutil/tests.c:434 crypto/dsa/dsa_sign.c:65  crypto/dsa/dsa_sign.c:67 | https://github.com/openssl/openssl/pull/16892  https://github.com/openssl/openssl/pull/16948 |
| CRYPTO_malloc                 | ssl/statem/statem_clnt.c:3174  2                             | https://github.com/openssl/openssl/pull/17412                |
| CRYPTO_strdup                 | apps/lib/engine_loader.c:91  apps/lib/app_rand.c:112 apps/lib/app_rand.c:32  apps/s_client.c:812 apps/req.c:1620 | https://github.com/openssl/openssl/pull/17110/  https://github.com/openssl/openssl/pull/17113  https://github.com/openssl/openssl/pull/17741  https://github.com/openssl/openssl/pull/17124 |
| EVP_CIPHER_CTX_new            | crypto/pem/pvkfmt.c:840                                      | https://github.com/openssl/openssl/pull/16892                |
| EVP_MD_CTX_new                | ssl/record/ssl3_record.c:1413                                | https://github.com/openssl/openssl/pull/17415                |
| EVP_PKEY_CTX_ctrl             | ssl/statem/statem_srvr.c:3246 ssl/statem/statem_srvr.c:3252  ssl/statem/statem_clnt.c:3076 ssl/statem/statem_clnt.c:3207 ssl/statem/statem_srvr.c:3213 | https://github.com/openssl/openssl/pull/17413                |
| i2s_ASN1_INTEGER              | crypto/x509/v3_sxnet.c:80                                    | https://github.com/openssl/openssl/pull/18608                |
| OBJ_new_nid                   | crypto/objects/obj_dat.c:765                                 | https://github.com/openssl/openssl/pull/18773                |
| OPENSSL_sk_new_null           | crypto/encode_decode/encoder_pkey.c:256 crypto/srp/srp_vfy.c:397 | https://github.com/openssl/openssl/pull/17836  https://github.com/openssl/openssl/pull/19435 |
| ossl_bio_new_from_core_bio    | providers/implementations/encode_decode/decode_pvk2key.c:87 providers/implementations/encode_decode/decode_epki2pki.c:70 providers/implementations/encode_decode/decode_pem2der.c:35 providers/implementations/encode_decode/decode_msblob2key.c:87 providers/implementations/encode_decode/encode_key2ms.c:41 providers/implementations/encode_decode/encode_key2ms.c:57 providers/implementations/encode_decode/encode_key2blob.c:32 providers/implementations/encode_decode/endecoder_common.c:91 | https://github.com/openssl/openssl/pull/17154                |
| OSSL_LIB_CTX_new              | test/tls-provider.c:841                                      | https://github.com/openssl/openssl/pull/17740                |
| OSSL_PARAM_BLD_new            | providers/implementations/keymgmt/dsa_kmgmt.c:195            | https://github.com/openssl/openssl/pull/17155                |
| sk_RSA_PRIME_INFO_new_reserve | crypto/rsa/rsa_backend.c:394                                 | https://github.com/openssl/openssl/pull/16892                |
| X509_get0_pubkey              | apps/lib/s_cb.c:1425                                         | https://github.com/openssl/openssl/pull/17176                |
| X509_NAME_new                 | test/ocspapitest.c:77                                        | https://github.com/openssl/openssl/pull/18774                |

# Linux

| related API      | location                                                     | link                                                         |
| ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| alloc_pages      | lib/test_meminit.c:69  lib/test_meminit.c:73                 | https://lkml.kernel.org/r/tencent_D44A49FFB420EDCCBFB9221C8D14DFE12908@qq.com |
| audit_log_start  | security/integrity/integrity_audit.c:47                      | https://lore.kernel.org/r/tencent_0685FF3C104366D05C368E2E0A88F043A507@qq.com/ |
| devm_kmalloc     | drivers/net/ethernet/xilinx/ll_temac_main.c:1427             | https://lore.kernel.org/r/tencent_CC2F97870384A231BC4689E51F04C4985905@qq.com |
| devm_kmalloc     | drivers/staging/wfx/main.c:296:40  2                         | https://lore.kernel.org/r/tencent_24A24A3EFF61206ECCC4B94B1C5C1454E108@qq.com/ |
| devm_kstrdup     | drivers/scsi/ufs/ufshcd-pltfrm.c:94  drivers/scsi/ufs/ufshcd-pltfrm.c:129 | https://lore.kernel.org/r/tencent_4257E15D4A94FF9020DDCC4BB9B21C041408@qq.com |
| devm_kstrdup     | drivers/gpio/gpio-merrifield.c:394                           | https://lore.kernel.org/r/tencent_A3850F2901FD5B80E831ABE7C27144509C0A@qq.com |
| devm_kstrdup     | drivers/nvmem/meson-mx-efuse.c:212                           | https://lore.kernel.org/r/tencent_0589E3FF08A4905922F78BC38602361C5505@qq.com |
| kmalloc          | lib/test_meminit.c:102 lib/test_meminit.c:105                | https://lkml.kernel.org/r/tencent_D44A49FFB420EDCCBFB9221C8D14DFE12908@qq.com |
| kmem_cache_alloc | lib/test_meminit.c:281 2 lib/test_meminit.c:299              | https://lkml.kernel.org/r/tencent_7CB95F1C3914BCE1CA4A61FF7C20E7CCB108@qq.com |
| kmemdup          | drivers/thunderbolt/icm.c:1745                               | https://lore.kernel.org/r/tencent_1AB342AE1B4723454E78A4D2FD3F33C81306@qq.com |
| kstrdup          | sound/core/jack.c:511                                        | https://lore.kernel.org/r/tencent_094816F3522E0DC704056C789352EBBF0606@qq.com |
| kstrdup          | sound/isa/gus/gus_mem.c:201  sound/isa/gus/gus_mem.c:245 sound/isa/gus/gus_mem.c:239 | https://lore.kernel.org/r/tencent_1E3950293AC22395ACFE99404C985D738309@qq.com |
| kstrdup          | fs/nfs/nfs4client.c:1372                                     | https://lore.kernel.org/r/tencent_818AD07038A58DFF31107CE6BB5C498E3607@qq.com |
| kstrdup          | drivers/media/usb/dvb-usb-v2/dvb_usb_core.c:1009             | https://lore.kernel.org/r/tencent_07FF16C8253370EE140700057438B052FD06@qq.com |
| kstrdup          | drivers/iio/dummy/iio_simple_dummy.c:618  2                  | https://lore.kernel.org/r/tencent_C920CFCC33B9CC1C63141FE1334A39FF8508@qq.com |
| kstrdup          | kernel/trace/trace_events_hist.c:3534                        | https://lkml.kernel.org/r/tencent_C52895FD37802832A3E5B272D05008866F0A@qq.com |
| kstrdup          | drivers/video/fbdev/via/viafbdev.c:1941  drivers/video/fbdev/via/viafbdev.c:1943  drivers/video/fbdev/via/viafbdev.c:1971  drivers/video/fbdev/via/viafbdev.c:1999  drivers/video/fbdev/via/viafbdev.c:1997 | https://lore.kernel.org/r/tencent_AD2E09472E455F78B792E6BF114813B35206@qq.com |
| kstrdup          | sound/soc/samsung/i2s.c:1351                                 | https://lore.kernel.org/r/tencent_EC21778DC383823CBC4069EA9F0B84943905@qq.com |
| kstrdup          | arch/arm/mach-mvebu/board-v7.c:134       arch/arm/mach-mvebu/board-v7.c:136       arch/arm/mach-mvebu/coherency.c:197 | https://lore.kernel.org/r/tencent_1D9E7394538085872BE9FD6780483137E70A@qq.com |
| kstrdup          | kernel/trace/trace_uprobe.c:1620                             | https://lkml.kernel.org/r/tencent_3C2E330722056D7891D2C83F29C802734B06@qq.com |
| kstrndup         | kernel/trace/trace_probe.c:358                               | https://lkml.kernel.org/r/tencent_4D6E270731456EB88712ED7F13883C334906@qq.com |
| kzalloc          | drivers/gpu/drm/msm/disp/mdp5/mdp5_plane.c:93                | https://lore.kernel.org/r/tencent_8E2A1C78140EE1784AB2FF4B2088CC0AB908@qq.com |
| kzalloc          | drivers/gpu/drm/msm/disp/msm_disp_snapshot_util.c:171        | https://lore.kernel.org/r/tencent_B3E19486FF39415098B572B7397C2936C309@qq.com |
| kzalloc          | drivers/staging/r8188eu/core/rtw_cmd.c:32                    | https://lore.kernel.org/r/tencent_1B6AAE10471D4556788892F8FF3E4812F306@qq.com |
| kzalloc          | drivers/iommu/msm_iommu.c:599                                | https://lore.kernel.org/r/tencent_EDB94B1C7E14B4E1974A66FF4D2029CC6D08@qq.com |
| kzalloc          | drivers/staging/r8188eu/core/rtw_p2p.c:37  drivers/staging/r8188eu/os_dep/xmit_linux.c:1526 | https://lore.kernel.org/r/tencent_B489FA9F0FC49CF92A77916394E225DC4705@qq.com |
| kzalloc          | drivers/staging/r8188eu/os_dep/xmit_linux.c:76               | https://lore.kernel.org/r/tencent_3B46EE3287288555389AD2EC3F388827B306@qq.com |
| kzalloc          | arch/arm/mach-mvebu/board-v7.c:130        arch/arm/mach-mvebu/coherency.c:196 | https://lore.kernel.org/r/tencent_1D9E7394538085872BE9FD6780483137E70A@qq.com |
| kzalloc          | drivers/clk/pxa/clk-pxa.c:104                                | https://lore.kernel.org/r/tencent_2B9817738F38B02844C245946EFF3B407E09@qq.com |
| kzalloc          | drivers/clk/meson/meson8b.c:3731                             | https://lore.kernel.org/r/tencent_FE734C50BC851F2AB5FE1380F833A7E67A0A@qq.com |
| kzalloc          | arch/mips/sgi-ip22/ip22-gio.c:365                            | https://lore.kernel.org/r/tencent_33384AA3FF65207ECC63B9531C1F1417E108@qq.com |
| kzalloc          | arch/mips/lantiq/falcon/sysctrl.c:168 arch/mips/lantiq/xway/gptu.c:123  arch/mips/lantiq/xway/sysctrl.c:316 arch/mips/lantiq/xway/sysctrl.c:341  arch/mips/lantiq/xway/sysctrl.c:359 arch/mips/lantiq/xway/sysctrl.c:360 arch/mips/lantiq/xway/sysctrl.c:403  arch/mips/lantiq/xway/sysctrl.c:408 | https://lore.kernel.org/r/tencent_3E071B85643888D2C8BF388804334CAE2706@qq.com |
| kzalloc          | drivers/clk/imx/clk-scu.c:836                                | https://lore.kernel.org/r/tencent_27FF59903EE6AB5C0D0E6D0A8E7059A59007@qq.com |

