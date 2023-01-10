| Target                                              | NUM  | reports_num | repeated | TP   | FP   | FN   |
| --------------------------------------------------- | ---- | ----------- | -------- | ---- | ---- | ---- |
| CWE121_Stack_Based_Buffer_Overflow                  | 36   | 0           | 0        | 0    | 0    | 36   |
| CWE122_Heap_Based_Buffer_Overflow                   | 36   | 0           | 0        | 0    | 0    | 36   |
| CWE131_Incorrect_Cal_BufSize                        | 42   | 0           | 0        | 0    | 0    | 42   |
| CWE476_NULL_DEF                                     | 36   | 0           | 0        | 0    | 0    | 36   |
| CWE590_Free_Memory_Not_on_Heap                      | 360  | 272         | 2        | 272  | 0    | 90   |
| CWE252_Unchecked_Return_Value                       | 270  | 266         | 0        | 266  | 0    | 4    |
| CWE253_Incorrect_Check_of_Function_Return_Value     | 270  | 182         | 0        | 182  | 0    | 88   |
| CWE390_Error_Without_Action                         | 72   | 0           | 0        | 0    | 0    | 72   |
| CWE401_Memory_Leak                                  | 474  | 368         | 86       | 336  | 32   | 224  |
| CWE404_Improper_Resource_Shutdown                   | 24   | 0           | 0        | 0    | 0    | 24   |
| CWE415_Double_Free                                  | 120  | 155         | 10       | 115  | 40   | 15   |
| CWE690_NULL_Deref_From_Return                       | 384  | 266         | 21       | 266  | 0    | 139  |
| CWE775_Missing_Release_of_File_Descriptor_or_Handle | 48   | 40          | 0        | 40   | 0    | 8    |
| Total                                               | 2172 | 1549        | 119      | 1477 | 72   | 814  |

| TYPE  | NUM  | reports_num | repeated | TP   | FP   | FN   | Precision | Recall  |
| ----- | ---- | ----------- | -------- | ---- | ---- | ---- | --------- | ------- |
| IPU   | 510  | 272         | 2        | 272  | 0    | 240  | 100.000%  | 52.941% |
| IEH   | 612  | 448         | 0        | 448  | 0    | 164  | 100.000%  | 73.203% |
| ICC   | 1050 | 829         | 117      | 757  | 72   | 410  | 91.315%   | 60.952% |
| Total | 2172 | 1549        | 119      | 1477 | 72   | 814  | 95.352%   | 62.523% |