#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lexer/lexer.h"

#define MAX_LINE_LENGTH 3000

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int main(int argc, char *argv[]) {

    char *src_folder;
    char *output_file;
    char *files;
    char **files_arr;

    if(argc == 3) {
        char *build_file_path = argv[2];
        char *build_arg = argv[1];

        if(build_arg == "-bf") {
                    // if build file exists
        if (access(build_file_path, 0) == 0) {
            char line[MAX_LINE_LENGTH] = {0};
            FILE *fp;
            // open buildfile
            fp = fopen(build_file_path, "r");
            if(fp == NULL) {
                printf("Failed to open file");
                // exits if failed
                exit(1);
            }
            int line_count = 0;
            while (line_count < 3)
            {
                fgets(line, MAX_LINE_LENGTH, fp);
                printf(line);

                if(line_count == 0) {
                    src_folder = line;
                }
                if(line_count == 1) {
                    output_file = line;
                }
                if(line_count == 2) {
                    files = line;
                }

                line_count++;
            }

            if(src_folder == NULL || output_file == NULL || files == NULL) {
                printf("Something went wrong when parsing the buildfile");
                exit(1);
            }

            files_arr = str_split(files, ',');
            char* curfile = "default";
            int curindex = 0;

            while(curfile != "+") {
                curfile = files_arr[curindex];
                LexContents("a");
            }

            printf("completed the build process");
            free(&fp);
        }
        else {
            printf("oh no the file doesn't exist!!");
        }
        } else if(build_arg == "-s") {
            // code for building singular file
        } else {
            printf("Invalid Build Argument!");
            exit(1);
        }
    } else {
        printf("Invalid Argument Count");
    }
}
