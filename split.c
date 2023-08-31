#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "split.h"

int isInSep(char c, const char *sep){
    for (int i = 0; i < strlen(sep); i++) {
        if (c == sep[i]) return 1;
    }
    return 0;
}

int getNumElements(const char *input, const char *sep){
    int count = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isInSep(input[i], sep) && !(isInSep(input[i+1], sep))){
            count++;
        }
    }
    return count + 1;
}

char **string_split(const char *input, const char *sep, int *num_words){
    const char *currentChar = input;
    char *stringToBeAdded = malloc(1);
    strcpy(stringToBeAdded, "");
    char **result;
    int index = 0;
    int count = 0;
    int skip = 0;
    *num_words = getNumElements(input, sep);
    result = calloc(sizeof(char *), *num_words);
    while (*currentChar != 0) {
        if (isInSep(*currentChar, sep) && skip) {
            currentChar++;
            count++;
            continue;
        }
        skip = 0;
        if (isInSep(*currentChar, sep) && count == 0) {
            //handle beginning case
            result[0] = malloc(1);
            strcpy(result[0], "");
            skip = 1;
            index += 1;
        }
        else if (*(currentChar+1) == '\0' && isInSep(*currentChar, sep)){
            result[index] = malloc(strlen(stringToBeAdded)+1);
            strcpy(result[index], stringToBeAdded);
            skip = 1;
            result[*num_words - 1] = malloc(1);
            strcpy(result[*num_words - 1], "");
            //add empty list to end of result
        }
        else if (isInSep(*currentChar, sep)) {
            //handle general case where sep char shows up in string
            skip = 1;
            result[index] = malloc(strlen(stringToBeAdded)+1);
            strcpy(result[index], stringToBeAdded);
            index++;
            strcpy(stringToBeAdded, "");
        }
        else if (!isInSep(*currentChar, sep)) {
            //handle normal case where the character is not in sep
            stringToBeAdded= realloc(stringToBeAdded, strlen(stringToBeAdded) + 1);
            strncat(stringToBeAdded, currentChar, 1);
            if (*(currentChar + 1) == 0) {
                //handle case where it is the last character
                result[index] = malloc(strlen(stringToBeAdded) + 1);
                strcpy(result[index], stringToBeAdded);
            }
        }

        currentChar++;
        count++;
    }
    free(stringToBeAdded);

    //time to print result
    for (int i = 0; i < *num_words; i++) {
        if (result[i] == 0) {
            result[i] = malloc(1);
            strcpy(result[i], "");
        }
        printf("[%s]", result[i]);
    }
    printf("\n");
    return result;
}

// int main(){
//     int size;
//     char **result = string_split(":::!foo:ff:asdf!happy:to::::be:!!!alive!:", "!:", &size);
//     //printf("size: %d\n", size);
//     // for (int i = 0; i<size; i++) {
//     //     printf("%s\n", result[i]);
//     // }
//     return 0;
// }