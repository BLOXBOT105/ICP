#include <stdlib>  

int system(const char *command);

int exit(retValue){
  return retValue;
}

char execute(command){
  system(command);
  char output[32] = "000000000000000000000000000000000000";
  return output;
}
