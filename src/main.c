#include <stdio.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 265

int main(int argc, char *argv[]) {

    char *src_folder;
    char *output_file;
    char *files;

    if(argc == 2) {
        char *build_file_path = argv[1];
        // if build file exists
        if (access(build_file_path, F_OK) == 0) {
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
        }
        else {
            printf("oh no the file doesn't exist!!");
        }
    } else {
        printf("Invalid Argument Count");
    }
}