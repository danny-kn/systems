.file "sum_arr_vals.s"
.section .rodata
sum_arr_vals_msg:
  .string "the sum is %d.\n"
.section .data
.align 8
arr_vals:
  .quad 10 # this val. represents the 1st elem.
  .quad 20 # ...                  the 2nd elem.
  .quad 30 # ...                  the 3rd elem.
  .quad 40 # ...                  the 4th elem.
  .quad 50 # ...                  the 5th elem.
  .quad 60 # ...                  the 6th elem.
n_val:
  .quad 6 # this val. represents the len.
.globl main
  .type main, @function
.section .text
main:
  pushq %rbp
  movq %rsp, %rbp
  movq $arr_vals, %rdi
  movq n_val, %rsi
  call sum_arr_vals
  movq $sum_arr_vals_msg, %rdi
  movq %rax, %rsi
  xorq %rax, %rax
  call printf
exit_01:
  leave
  ret
.size main, .-main
.globl sum_arr_vals
  .type sum_arr_vals, @function
.section .text
sum_arr_vals:
  pushq %rbp
  movq %rsp, %rbp
  xorq %rax, %rax
  xorq %rdx, %rdx
iter:
  cmpq %rsi, %rdx
  jge exit_02
  addq (%rdi, %rdx, 8), %rax
  incq %rdx
  jmp iter
exit_02:
  leave
  ret
.size sum_arr_vals, .-sum_arr_vals
