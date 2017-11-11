#include<asm/unistd_64.h>

#define S(n) .globl n;n:;mov %rcx,%r10;mov $__NR_##n,%rax;syscall;ret;

S(read)S(write)S(open)S(close)S(fstat)S(mmap)S(munmap)S(exit)

