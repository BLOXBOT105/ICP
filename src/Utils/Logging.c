#include "Logging.h"

// 1 if file exists
// 2 if file doesn't
int CheckLogExistence() {
    int file_exists = 0;
    
    if (access("compiler_log.log", F_OK) == 0) {
        return 1;
    } else {
    return 0;
    }

    return 0;
}

int u__clean_log__() {
    remove("compiler_log.log");
    FILE *fptr = fopen("compiler_log.log", "w")
    fclose(fptr)
    return 1;
}

void WriteToLog(string log, int elevation = 1) {
   FILE *fptr;
   fptr = fopen("compiler_log.log","w");
    if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

    log = time_str + " - " + log;

   fprintf(fptr,"%d",log);
   fclose(fptr);
}