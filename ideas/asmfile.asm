main: ;; function main with 0 args
   PUSH %BP
   MOV  %SP, %BP
   
@main_body: ;; contents of main
   SUB  %SP, $4, %SP
   MOV  $1, -4(%BP) ;; $return value
   MOV  -4(%BP), %13
   JMP  @main_exit ;; return called
   
@main_exit: ;; return
   MOV  %BP, %SP
   POP  %BP
   RET 
