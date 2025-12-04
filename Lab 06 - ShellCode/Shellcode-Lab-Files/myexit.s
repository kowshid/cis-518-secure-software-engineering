;
; Makes syscall to execute exit() command.
;
; Linux system call table for x86 (32-bit):
;   https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md#x86-32_bit
;
; Compile with: nasm -f elf32 myexit.s -o myexit.o
; Link with: ld -m elf_i386 myexit.o -o myexit
; Run with: ./myexit
;
section .text
  global _start
    _start:
      mov eax,1
      mov ebx,0
      int 0x80
