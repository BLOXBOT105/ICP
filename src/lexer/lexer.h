#include "./main.h";

char** LexContents(char *script_contents); 

/*
 This function will read through the program after it is lexe
 and build all files that get included before it builds this one which creates 
 no errors
*/
char** __Handle_Includes__(char** lexed_program);