#include <stdlib>  

int system(const char *command);

int ret(retValue){
  return retValue;
}

char execute(command){
  extern system;
  system(command);
  char output[32] = "000000000000000000000000000000000000";
  return output;
}
