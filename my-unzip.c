/*
 * my-unzip.c
 * CT30A3370
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int unzip(FILE *fp) {
    // variable for char
    char c;
    // number of chars
    uint32_t count;
    // return value for fread
    size_t ret;
    while(1) {
        // Reading number
        if ((ret = fread(&count, sizeof(uint32_t), sizeof(uint32_t), fp)) == 0) {
            break;
        }
        // Check for fread success
        // Source fread man page
        if (ret != sizeof(uint32_t)) {
            fprintf(stderr, "fread() failed: %zu\n", ret);
            exit(1);
        }

        // Reading char
        if ((ret = fread(&c, sizeof(char), sizeof(char), fp)) == 0) {
            break;
        }
        // Check for fread success
        // Source fread man page
        if (ret != sizeof(char)) {
            fprintf(stderr, "fread() failed: %zu\n", ret);
            exit(1);
        }

        for (int i = 0; i < count; i++) {
            fprintf(stdout, "%c", c);
        }
    }
    // Print newline at the end
    fprintf(stdout, "\n");
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
            perror("my-unzip: cannot open file\n");
            return 1;
        }
        if (unzip(fp) != 0) {
            perror("my-unzip: weird error\n");
            return 1;
        }
        if (fclose(fp) != 0) {
            perror("my-unzip: unable to close file\n");
            return 1;
        }
    }

    // End program
    return 0;
}