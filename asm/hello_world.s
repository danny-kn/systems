.file "hello_world.s"
.section .rodata
hello_world_msg:
  .string "hello, world!\n"
.globl main
  .type main, @function
.section .text
main:
  pushq %rbp
  movq %rsp, %rbp
  movq $hello_world_msg, %rdi
  xorq %rax, %rax
  call printf
exit:
  leave
  ret
.size main, .-main
