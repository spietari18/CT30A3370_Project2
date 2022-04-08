/*
 * my-zip.c
 * CT30A3370
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int zip(FILE *fp) {
    // current and previous char
    char c, co;
    uint32_t i = 0;
    while ((c = fgetc(fp))) {
        // Begin of the file
        if (i == 0) {
            co = c;
            i = 1;
            continue;
        }
        // If char equals previous
        if (c == co) {
            i++;
            continue;
        }
        // If char differs from previous
        if (c != co) {
            fwrite(&i, sizeof(int32_t), sizeof(int32_t), stdout);
            fwrite(&co, sizeof(char), sizeof(char), stdout);
            co = c;
            i = 1;
            // If EOF
            if (c == EOF) {
                break;
            }
            continue;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    // Define variables
    FILE *fp;

    // Check amount of arguments
    if (argc < 2) {
        return 0;
    }

    // Loop through all given files
    for (int i = 1; i < argc; i++) {
        // Open file, handle possible errors
        if ((fp = fopen(argv[i], "r")) == NULL) {
            perror("my-zip: cannot open file\n");
            return 1;
        }
        if (zip(fp) != 0) {
            perror("my-zip: weird error\n");
            return 1;
        }
        if (fclose(fp) != 0) {
            perror("my-zip: unable to close file\n");
            return 1;
        }
    }

    // End program
    return 0;
}