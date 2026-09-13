#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *str){
    char *keywords[10] = {"int", "float", "char", "double", "if",
                           "else", "while", "for", "return", "void"};
    for(int i=0; i<10; i++){
        if(strcmp(str,keywords[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int isLibraryFun(char *str){
    char *library[3] = {"printf","scanf","strcmp"};
    for(int i=0; i<3; i++){
        if(strcmp(str,library[i]) == 0){
            return 1;
        }
    }
    return 0;
}


int isDirective(char *str){
    if(str[0] == '#'){
        return 1;
    }
    return 0;
}


int isOperator(char *str){
    char *operators[] = {"+","-","*","/","<",">",">=","<=","==","!=","="};
    for(int i=0; i<11; i++){
        if(strcmp(str,operators[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int isSpecialChar(char *str) {
    char *special[] = {
        ";", ",", "(", ")", "{", "}", "[", "]"
    };

    int n = sizeof(special) / sizeof(special[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(str, special[i]) == 0) {
            return 1;  
        }
    }

    return 0;           
}


int isIdentifier(char *str){
    if(!isalpha(str[0]) && str[0] != '_'){
        return 0;
    }
    for(int i=1; str[i] != '\0'; i++){
        if(!isalnum(str[i]) && str[i] != '_'){
            return 0;
        }
    }
    return 1;
}

int main(){
    FILE *fp;
    char word[100];
    fp = fopen("input.txt","r");
    if(fp == NULL){
        printf("Error while opening the file.\n");
        return -1;
    }
    while(fscanf(fp,"%s",word) != EOF){
        if (strcmp(word, "stdio.h") == 0) {
           printf("%s is a Header File\n", word);
        }
        else if(isKeyword(word)){
            printf("%s is a keyword\n",word);
        }
        else if(isLibraryFun(word)){
            printf("%s is a Library Function\n",word);
        }
        else if(isDirective(word)){
            printf("%s is a Directive\n",word);
        }
        else if(isdigit(word[0])){
            if(strchr(word,'.') !=NULL)
                printf("%s is a float\n",word);
            else
                printf("%s is a int\n",word);
        }
        else if(isOperator(word)){
            printf("%s is an Operator\n",word);
        }
        else if(isSpecialChar(word)){
            printf("%s is a Special Character\n",word);
        }
        else if(isIdentifier(word)){
            printf("%s is an Identifier\n",word);
        }
        else{
            printf("%s is Unknown/Mixed token\n",word);
        }
    }
    fclose(fp);
    return 0;
}

/*
Design and implement a lexical analyzer using C language to recognize all valid
tokens in the input program. The lexical analyzer should ignore redundant spaces, tabs
and newlines. It should also ignore comments.
INPUT
#include stdio.h
int main ( )
{
    int c = 8 ;
    float total = 3.14 ;
    c = c + 1 ;
    printf hello
    return 0 ;
}
    
OUTPUT
#include is a Directive
stdio.h is a Header File
int is a keyword
main is an Identifier
( is a Special Character
) is a Special Character
{ is a Special Character
int is a keyword
c is an Identifier
= is an Operator
8 is a int
; is a Special Character
float is a keyword
total is an Identifier
= is an Operator
3.14 is a float
; is a Special Character
c is an Identifier
= is an Operator
c is an Identifier
+ is an Operator
1 is a int
; is a Special Character
printf is a Library Function
hello is an Identifier
return is a keyword
0 is a int
; is a Special Character
} is a Special Character
*/