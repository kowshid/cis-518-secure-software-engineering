;
; Makes syscall to execve() to execute the command: /bin/sh
;
; Linux system call table for x86 (32-bit):
;   https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md#x86-32_bit
;
; In the x86 architecture, to use execve() system call, we need to set the
; general purpose registers as follows:
;   eax: must contain 11, which is the system call number for execve()
;   ebx: must contain the address of the command string (e.g., "/bin/sh")
;   ecx: must contain the address of the argument array
;   edx: must contain the address of the environment variables that we want to
;        pass to the new program. If there are no environment variables to pass,
;        set edx to 0.
;
; Compile with: nasm -f elf32 mysh.s -o mysh.o
; Link with: ld -m elf_i386 mysh.o -o mysh
; Run with: ./mysh
;
section .text
  global _start
    _start:
      ; store the argument string "/bin/sh" on stack
      xor  eax, eax       ; eax = 0x00000000
      push eax            ; use 0 to terminate the string
      push "//sh"
      push "/bin"
      mov  ebx, esp       ; ebx = address of command "/bin/sh"

      ; setup argv[] array on stack
      push eax            ; argv[1] = 0
      push ebx            ; argv[0] points "/bin//sh"
      mov  ecx, esp       ; ecx = address of argv[]
   
      ; no environment variables to pass to execve() 
      xor  edx, edx       ; edx = 0x00000000

      ; set eax register with system call number for execve()
      xor eax,eax         ; eax = 0x00000000
      mov al,0x0b         ; eax = 0x0000000b
        
      int 0x80            ; invoke execve() system call
