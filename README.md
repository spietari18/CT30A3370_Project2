# CT30A3370_Project2 Unix Utilities
## my-cat
usage:
\$ ./my-cat file1 [file2 file3...]

My-cat prints out all given files.
If no files are given, my-cat just exits.

## my-grep
usage:
\$ ./my-grep keyword [file file2...]

My-grep search keyword from given input. If no file is given, default input is standard input.
My-grep prints out all lines where keyword is.

## my-zip
usage:
\$ ./my-zip file [file2 file3...]

My-zip compresses given input and prints it to standard output. The output can be redirected to file if wanted.
Multiple files are all compressed into one file, so data is kept, but theres no automatic way to separete the files.

## my-unzip
usage:
\$ ./my-unzip file [file2 file3...]

My-unzip decompresses given input and prints it to standard output. The output can be redirected to file if wanted.
If multiple files are compressed into one, my-unzip could not separete the files.
If multiple input files are given, all data is outputted to standatd output with no breaks.