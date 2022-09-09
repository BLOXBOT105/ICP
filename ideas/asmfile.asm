section .text
   global _entry

_entry: ;; defines entry function
   jmp @main
   
@main: ;; function perameters/arguments
   void db "VOID",0xa
   jmp @main_body

@main_body: ;; function contents
   mov eax, 4
   jmp @main_return
   
@main_return: ;; return value from function
   mov eax, 1
   mov ebx, 3
   int 0x80
