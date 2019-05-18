%{
#include <iostream>
#include <stdio.h>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include "Symbol.hpp"
#include "lex.yy.cpp"
using namespace std;

enum type{
    STRING_type,
    INTEGER_type,
    REAL_type,
    BOOLEAN_type
};


int yylex();
void yyerror(string error_str);
vector<SymbolTable> stack;

%}

%union{
    int val;
    double dval;
    std::string* sval;
    DataItem* id_data;
    bool bval;
    int type;
};

%token AND OR EQ LE_EQ GR_EQ NEQ
%token ARRAY BOOLEAN _BEGIN BREAK CHAR CASE CONST CONTINUE DO ELSE END EXIT 
%token FALSE FOR FN IF IN INTEGER LOOP MODULE PRINT PRINTLN PROCEDURE REPEAT 
%token RETURN REAL STRING RECORD THEN TURE TYPE USE UTIL VAR WHILE
%token OF READ
%token <sval> IDENTIFIER
%token <val> INT_CONST
%token <dval> REAL_CONST
%token <sval> STR_CONST
%token <bval> BOOLEAN_CONST
//%type <id_data> const_value
// expression function_invocation
//%type <type> data_type
/*precedence*/
%left '*' '/'
%left '+' '-'
%left '<' LE_EQ '=' GR_EQ '>' NEQ
%left '~'
%left AND 
%left OR
%nonassoc UMINUS

%%

program:    MODULE IDENTIFIER optional_var_con_declaration Procedure_dec _BEGIN optional_statement END IDENTIFIER '.'
    
            ;

Procedure_dec:  PROCEDURE IDENTIFIER optional_arg_parentheses opt_func_type optional_var_con_declaration 
                _BEGIN optional_statement END IDENTIFIER ';'
                |
                ;

optional_var_con_declaration:  constants optional_var_con_declaration
                            |  variables optional_var_con_declaration
                            |   
                            ;

constants:  CONST IDENTIFIER '=' expression ';'
        |   IDENTIFIER '=' expression ';' 
         ;

variables:      VAR opt_IDENTIFIER ':' data_type ';'
            |   IDENTIFIER ':' data_type ';'
            |   IDENTIFIER ':' ARRAY '[' INT_CONST ',' INT_CONST ']' OF data_type ';'
            ;
                        
opt_IDENTIFIER:		IDENTIFIER ',' opt_IDENTIFIER
	      |		IDENTIFIER
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
            |   BOOLEAN_CONST 
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
	        |	expression ';'
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

conditional_statement:      IF '(' expression ')' THEN optional_statement ELSE optional_statement END ';'
                        |   IF '(' expression ')' THEN optional_statement END ';'
                        ;

loop_statement: WHILE '(' expression ')' DO optional_statement END ';'
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

void yyerror(string error_str){
    cout << error_str;
}
int yywrap(){
    return 1;
}

int main(){
    SymbolTable global;
    stack.push_back(global);
    yyparse();
    // cout << ("\n--------------------------------------------\n\t\tSymbol Table");
    // cout << ("\n--------------------------------------------\n");
    // cout << ("Name\tType\tValue\t\tentries\n");
	return 0;	
}
