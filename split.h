


//Returns 1 or 0 depending on whether the character c is in the string sep
int isInSep(char c, const char *sep);

//returns an int representing the number of list elements the result of string_split will have
int getNumElements(const char *input, const char *sep);

//splits a string into a list of string based on the delimiters 
char **string_split(const char *input, const char *sep, int *num_words);