/*
 * my-grep.c
 * CT30A3370
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/limits.h>

int grep(char *searchterm, FILE *fp) {
    // Define variables
    char *buffer = NULL;
    ssize_t nread;
    size_t len;

    // Read from file to buffer
    while ((nread = getline(&buffer, &len, fp)) != -1) {
        if (strstr(buffer, searchterm) != NULL) {
        // Print to stdout
        fwrite(buffer, nread, 1, stdout);
        }
    }
    free(buffer);
    return 0;
}

int main(int argc, char **argv) {
    // Define variables
    FILE *fp;
    char searchterm[PATH_MAX];

    // Check amount of arguments
    if (argc < 2) {
        printf("my-grep: searchterm [file ...]\n");
        return 1;
    }

    strcpy(searchterm, argv[1]);

    // Check if inputfile is given
    if (argc == 2) {
        // Set input to be stdin
        fp = stdin;
    } else {
        // Loop through all given files
        for (int i = 2; i < argc; i++) {
            // Open file, handle possible errors
            if ((fp = fopen(argv[i], "r")) == NULL) {
                perror("my-grep: cannot open file\n");
                return 1;
            }
            if (grep(searchterm, fp) != 0) {
                perror("my-grep: weird error\n");
                return 1;
            }
            if (fclose(fp) != 0) {
                perror("my-grep: unable to close file\n");
                return 1;
            }
        }
    }

    // End program
    return 0;
}