/*
 * my-cat.c
 * CT30A3370
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>

int cat(FILE *fp) {
    // Define variables
    char buffer[PATH_MAX];

    // Read from file to buffer
    while ((fgets(buffer, sizeof(buffer), fp)) != NULL) {
        // Print to stdout
        printf("%s", buffer);
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
            perror("my-cat: cannot open file\n");
            return 1;
        }
        if (cat(fp) != 0) {
            perror("my-cat: weird error\n");
            return 1;
        }
        if (fclose(fp) != 0) {
            perror("my-cat: unable to close file\n");
            return 1;
        }
    }

    // End program
    return 0;
}
