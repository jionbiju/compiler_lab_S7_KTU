%{
    #include "y.tab.h"
%}

%%
[0-9]+ {yylval = atoi(yytext);
        return num;}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"=" {return '=';}
"(" {return '(';}
")" {return ')';}
"^" {return '^';}
. {return yytext[0];}
%%

int wrap(){
    return 1;
}