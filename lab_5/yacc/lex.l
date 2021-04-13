%{
#include <stdio.h>
#include "bison.tab.h"
int line_no = 0;
%}

%%
\'[a-zA-Z0-9!@#$%^&*()_=? ]\' 		{printf("CHAR\n");return(CHAR);}
\"[a-zA-Z0-9!@#$%^&*()_=? ]+\"         	{printf("STRING\n");return(STRING);}
";"                   		{printf(";\n");return(SEMICOLON);}
"+"                    	{printf("+\n");return(CONCATENATION);}
" "
\n                     line_no++;
%%

yywrap () {
  return (0);
}
