//
// Filename: shellcode1.c
//
// Compile with: gcc -m32 shellcode1.c
//
// Extract machine code with: objdump -Mintel --disassemble a.out
//
// Discussion: two obvious problems with extracting shellcode this way
//      1. Many calls to dynamically linked functions
//      2. Many zeros in the machine code that cause strcpy() to stop
//         when a zero is found in the source string
//

#include <unistd.h>

void main()
{
    char *argv[2];
    argv[0] = "/bin/sh";
    argv[1] = NULL;
    execve(argv[0],argv,NULL);
}
