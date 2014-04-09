%{
    #include "y.tab.h"
%}
num [0-9]

%%
\n {return NL;}
0 {return '0';}
1 {return '1';}

%%
