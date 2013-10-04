%{
#include"y.tab.h"
%}

char [a-zA-Z0-9]
iden [a-zA-Z][a-zA-Z0-9]*
number [0-9]*

%%

switch { return SWITCH; }
case { return CASE; }
break { return BREAK; }
default { return DEF; }
\'{char}\' {return CHAR;}
{iden} {return ID;}
{number} {return NUM;}
\* return '*';
\+ return '+';
\= return '=';
\( {return '('; }
\) {return ')'; }
\{ {return '{'; }
\} {return '}'; }
\: {return ':'; }
\; {return ';';}


%%
