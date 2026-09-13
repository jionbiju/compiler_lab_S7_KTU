%{
#include "y.tab.h"
%}

%%

[0-9]+  { return num; }
[a-zA-Z_][a-zA-Z0-9]*   { return id; }

"+" { return '+'; }
"-" { return '-'; }
"*" { return '*'; }
"/" { return '/'; }
"(" { return '('; }
")" { return ')'; }
"^" { return '^'; }

[ \t\n] { }

. { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}