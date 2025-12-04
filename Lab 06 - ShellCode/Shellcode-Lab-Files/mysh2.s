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
; Compile with: nasm -f elf32 mysh2.s -o mysh2.o
; Link with: ld --omagic -m elf_i386 mysh2.o -o mysh2
; Run with: ./mysh2
;
section .text
  global _start
    _start:
        BITS 32
        jmp short two
        
    one:
        pop ebx             ; ebx = address of "/bin/sh"
        xor eax,eax         ; eax = 0
        mov [ebx+7],al      ; replace the * in db section with 0

        ; setup argv[] array on stack
        mov [ebx+8],ebx     ; argv[0] = address of "/bin/sh"
        mov [ebx+12],eax    ; argv[1] = 0
        lea ecx,[ebx+8]     ; ecx = ebx + 8

        ; no environment variables to pass to execve()
        xor edx,edx

        ; set eax register with system call number for execve()
        xor eax,eax         ; eax = 0x00000000
        mov al,0x0b         ; eax = 0x0000000b
        
        int 0x80            ; invoke execve() system call
      
    two:
        call one
        db '/bin/sh*AAAABBBB' 
