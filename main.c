#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

int main(int argc, char *argv[]){
    char *sep = malloc(1);
    strcpy(sep, "");
    if (argc < 2){
        sep = realloc(sep, 2);
        strcpy(sep, " ");
    }
    else {
        for (int i = 1; i < argc; i++){
            sep = realloc(sep, strlen(sep) + strlen(argv[i]));
            strcat(sep, argv[i]);
        }
    }
    //printf("sep: %s\n", sep);

    char *Buffer = calloc(4000, 1);

    int size;
    while(1){
        fscanf(stdin, "%s", Buffer);
        //printf("you entered: %s\n", Buffer);
        if (strlen(Buffer) == 1 && Buffer[0] == '.') break;
        string_split(Buffer, sep, &size);
    }
    free(sep);
    free(Buffer);
    return 0;
}