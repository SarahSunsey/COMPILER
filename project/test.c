#include "stackk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* replaceStringIncrementDecrement(char* input) {
    // Check if the input is valid
    if (input == NULL) {
        return NULL;
    }

    // Find occurrences of any string++, any string--
   
    int length = strlen(input) ;
    char output[length*3]; 
    for (int i = 0; i < length; i++){
        if (input[i+1]=='+'){
            if(input[i+2]=='+'){
                if(i==0){
                 strcpy(output, input[0] );
                 strcat(output, ":=");
                 strcat(output, input[0]);
                 strcat(output, "+1");
                }
            }
        }
    }

        return input;
}