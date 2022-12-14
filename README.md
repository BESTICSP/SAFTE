# SAFTE: Self-injection based Anti-Fuzzing TEchniques

Fuzzing is a set of software testing techniques designed to find implementation bugs automatically. Developers leverage fuzzing to assess the applications' security and stability. Unfortunately, the threat actors can also use fuzzing to find zero-day vulnerabilities, known as fuzzing attacks. Therefore, researchers utilize anti-fuzzing technologies to slow down and frustrate these malicious aggressors. However, the main aim of these methods is to design a source-level defense strategy, which means this work requires not only the source codes but also considering the programming language. This restricts users from protecting the released binary executable they do not own from malicious analysis.

In this paper, we perform a systematic analysis of software protection techniques and design a new anti-fuzzing method, called SAFTE, which can help users defend against fuzzing attacks. This strategy is a binary-level scheme that is based on self-injection. More specifically, it is implemented by dynamic loading and execution. First, we allocate a memory block and copy the image stored in the ".data" into the allocated local memory. After modifying the memory with execute permissions, it will execute the image in the memory. Since this scheme hides the running and process status of the program, the fuzzer cannot get the correct feedback or the crash information of the target program. Therefore, it makes the fuzzer completely useless. Our evaluation on popular fuzzers demonstrates that SAFTE can prevent most existing fuzzers and performs better than state-of-the-art anti-fuzzing methods. Meanwhile, the size of the program that was modified by SATFE only increases no more than 5MB and the running time only increases by 0.02ms, which is much better than the other methods.

How to use:

Our proposed program is in the "safe" folder. Users can use this program to modify a binary program. The modified program can prevent fuzzing.

The codes in the folder "Experiment" are mainly used to prove that the fuzzer cannot detect the code path in the shellcode.

We will upload more details after the paper finishes the review process.
