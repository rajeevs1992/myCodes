%{
#include"y.tab.h"
%}

iden [a-zA-Z][a-zA-Z0-9]*
number [0-9]*

%%

for { return FOR; }
{iden} {return ID;}
{number} {return NUM;}
\* return '*';
\+ return '+';
\= return '=';
\, return ','; 
\( {return '('; }
\) {return ')'; }
\{ {return '{'; }
\} {return '}'; }
\<|\>|\&\&|\|\||\=\= {return COND; }
\; {return ';';}


%%
