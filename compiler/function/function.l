%{
#include"y.tab.h"
%}

iden [a-zA-Z][a-zA-Z0-9]*

%%

int|void|char|float {return KEYWORD;}
{iden} {return ID;}
\* return '*';
\( {return '('; }
\) {return ')'; }
\; {return ';';}
\, {return ',';}
\n {return '\n';}


%%
