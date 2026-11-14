%{
    #include <stdio.h>
    int upper = 0, lower = 0, digit = 0, special = 0;
    int len = 0;
%}

%%

[A-Z]   { upper = 1; len++; }

[a-z]   { lower = 1; len++; }

[0-9]   { digit = 1; len++; }

[^a-zA-Z0-9\n] { special = 1; len++; }

. {}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter password: ");
    yylex();
    if(len >= 8 && upper && lower && digit && special)
        printf("Valid Password\n");
    else
        printf("Invalid Password\n");
    return 0;
}
/*
Write a LEX program to check whether a password is valid or not.
[ hint : A password is correct if it contains: Atleast 1 uppercase character,
Atleast 1 lowercase character, Atleast 1 digit, Atleast 1 special character
and Minimum 8 characters ]

OUTPUT:
Enter password: aBCD&12354aaA
Valid Password
Enter password: Abcd12345
Invalid Password
*/