%{
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int  yylex  (void);
void yyerror(const char *s);
//int linenum = 1;
//char table[256][256];
//int table_index = 0;
%}

%union{
    int val;
    double dval;
    char* sval;
    int bval;
    int type;
};

%token AND OR EQ LE_EQ GR_EQ NEQ
%token ARRAY BOOLEAN T_BEGIN BREAK CHAR CASE CONST CONTINUE DO ELSE END EXIT FALSE FOR FN IF IN INTEGER LOOP MODULE PRINT PRINTLN PROCEDURE REPEAT RETURN REAL STRING RECORD THEN TURE TYPE USE UTIL VAR WHILE
%token OF READ
%token <sval> IDENTIFIER
%token <val> INT_CONST
%token <dval> REAL_CONST
%token <sval> STR_CONST
%token <bval> BOOL_CONST
//%type <type> var_type
//%start program
/*precedence*/
%left '*' '/'
%left '+' '-'
%left '<' LE_EQ '=' GR_EQ '>' NEQ
%left '~'
%left AND 
%left OR
%nonassoc UMINUS

%%

program:    MODULE IDENTIFIER
            optional_var_con_declaration 
            Procedure_dec 
            mod_begin_end
            ;

Procedure_dec:  PROCEDURE IDENTIFIER optional_arg_parentheses opt_func_type
                optional_var_con_declaration
                pro_begin_end
                |
                    ;   
mod_begin_end:  T_BEGIN
            optional_statement
            END IDENTIFIER '.'
            ;

pro_begin_end:
                 T_BEGIN
                 optional_statement
                 END IDENTIFIER ';'
                ;

optional_var_con_declaration:  constants optional_var_con_declaration
                            |  variables optional_var_con_declaration
                            |   
                            ;

constants:  CONST IDENTIFIER '=' expression ';' 
        |   IDENTIFIER '=' expression ';' 
         ;

variables:      VAR IDENTIFIER ':' data_type ';'
            |   IDENTIFIER ':' data_type ';'
            |   IDENTIFIER ':' ARRAY '[' INT_CONST ',' INT_CONST ']' OF data_type ';'
            ;
                            
optional_arg_parentheses: '(' optional_arguments ')'
                |
                ;

optional_arguments: IDENTIFIER ':' data_type
                |   optional_arguments ',' IDENTIFIER ':' data_type
                |   
                ;

opt_func_type: ':' data_type
            |
            ;

data_type:      STRING
            |   INTEGER
            |   BOOLEAN
            |   REAL
            ;

const_value:    INT_CONST
            |   BOOL_CONST
            |   REAL_CONST
            |   STR_CONST
            ;

statement:      IDENTIFIER EQ expression ';'
            |   IDENTIFIER '[' expression ']' EQ expression ';'
            |   PRINT expression ';'
            |   PRINTLN expression ';'
            |   READ IDENTIFIER ';'
            |   RETURN ';'
            |   RETURN expression ';'
            |   function_invocation ';'
            |   conditional_statement
            |   loop_statement
            ;

expression:     IDENTIFIER
            |   const_value
            |   function_invocation
            |   expression '*' expression
            |   expression '/' expression
            |   expression '+' expression
            |   expression '-' expression
            |   expression '<' expression
            |   expression '>' expression
            |   expression '=' expression
            |   expression LE_EQ expression
            |   expression GR_EQ expression
            |   NEQ expression
            |   '~' expression
            |   expression AND expression
            |   expression OR expression
            |   IDENTIFIER '[' expression ']'
            |   '(' expression ')'
            |   '-' expression %prec UMINUS
            ;

conditional_statement:      IF '(' expression ')' THEN
                            optional_statement
                            ELSE
                            optional_statement
                            END ';'
                        |   IF '(' expression ')' THEN
                            optional_statement
                            END ';'
                        ;

loop_statement: WHILE '(' expression ')' DO 
                optional_statement
                END ';'
                ;

optional_statement:    statement optional_statement
                    |  statement
                    ;

function_invocation:    IDENTIFIER '(' optional_comma_separated_expression ')'
                    ;

optional_comma_separated_expression:    expression
                                    |   optional_comma_separated_expression ',' expression
                                    ;

%%

//int yywrap(){
//	return 1;
//}
void yyerror(const char *str){
    printf("error:%s\n",str);
}
int yywrap(){
    return 1;
}

int main(){
	//yylex();
	//printf("\nSymbol Table: \n");
	//for(int i = 0; i < table_index; i++)
	//	printf("%s\n",table[i]);
    yyparse();
	return 0;	
}
