%{#include<stdio.h>%}

%token CHAR
%token STRING
%token CONCATENATION
%token SEMICOLON

%%
mult_operations : rev_operation_s | mult_operations rev_operation_s
rev_operation_s : rev_operation SEMICOLON
rev_operation : single_operation | rev_operation CONCATENATION operand
single_operation : operand CONCATENATION operand
operand : CHAR | STRING
%%

extern int line_no;
extern char *yytext;

int yyerror(s)
char *s;
{
  fprintf(stderr, "%s: at or before '%s', line %d\n", s, yytext, line_no);
}

main (void) {
    setlocale(0,"");
    if(yyparse()){
      printf("error"); 
    }
    else {
      printf("good"); 
    }
    return;
}
