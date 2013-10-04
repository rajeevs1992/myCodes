%{
#include"y.tab.h"
%}

iden [a-zA-Z][a-zA-Z0-9]*
number [0-9]*

%%

while { return WHILE; }
do {return DO;}
{iden} {return ID;}
{number} {return NUM;}
\* return '*';
\+ return '+';
\= return '=';
\( {return '('; }
\) {return ')'; }
\{ {return '{'; }
\} {return '}'; }
\&\&|\|\||\=\= {return COND; }
\; {return ';';}


%%
