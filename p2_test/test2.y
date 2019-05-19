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
#define TRACE_FLAG 1
#define Trace(t) if (TRACE_FLAG) cout << "TRACE => " << t <<endl;
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
    int _val;
    double d_val;
    std::string* s_val;
    DataItem* id_data;
    bool b_val;
    int type;
};

%token AND OR EQ LE_EQ GR_EQ NEQ
%token ARRAY BOOLEAN _BEGIN BREAK CHAR CASE CONST CONTINUE DO ELSE END EXIT 
%token FALSE FOR FN IF IN INTEGER LOOP MODULE PRINT PRINTLN PROCEDURE REPEAT 
%token RETURN REAL STRING RECORD THEN TURE TYPE USE UTIL VAR WHILE
%token OF READ
%token <s_val> IDENTIFIER
%token <_val> INT_CONST
%token <d_val> REAL_CONST
%token <s_val> STR_CONST
%token <b_val> BOOLEAN_CONST
%type <id_data> const_value expression function_invocation
//%type <id_data> opt_IDENTIFIER
%type <type> data_type 
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



Procedure_dec:  PROCEDURE IDENTIFIER 
                optional_arg_parentheses opt_func_type optional_var_con_declaration 
                _BEGIN optional_statement END IDENTIFIER ';'
                | 
                ;

optional_var_con_declaration:  constants optional_var_con_declaration
                            |  variables optional_var_con_declaration
                            {

                            }
                            |   
                            ;

constants:  CONST IDENTIFIER '=' expression ';'
        {
            $4 -> IdName = *$2;
            int a=stack.back().insert(*$2,*($4));
            if(a)
                cout<<"insert successful!";
        }
        |   IDENTIFIER '=' expression ';' 
        {
            $3 -> IdName = *$1;
            int a=stack.back().insert(*$1,*($3));
            if(a)
                cout<<"insert successful!";
        }
        ;

variables:      VAR opt_IDENTIFIER ':' data_type ';'
            |   IDENTIFIER ':' ARRAY '[' INT_CONST ',' INT_CONST ']' OF data_type ';'
            ;
                        
opt_IDENTIFIER:		IDENTIFIER ',' opt_IDENTIFIER
	      |		IDENTIFIER
	      ;

optional_arg_parentheses: '(' optional_arguments ')'
                |
                ;

optional_arguments: IDENTIFIER ':' data_type
                {
                    struct DataItem* tempData;
                    tempData->IdName=*$1;
                    tempData->type=$3;
                    stack.back().insert(*$1,*tempData);
                }
                |   optional_arguments ',' IDENTIFIER ':' data_type
                {
                    struct DataItem* tempData;
                    tempData->IdName=*$3;
                    tempData->type=$5;
                    stack.back().insert(*$3,*tempData);
                }
                |   
                ;

opt_func_type: ':' data_type
            |
            ;

data_type:      STRING { $$=STRING_type; }
            |   INTEGER { $$=INTEGER_type; }
            |   BOOLEAN {$$=BOOLEAN_type;}
            |   REAL {$$=REAL_type;}
            ;

const_value:    INT_CONST {
                struct DataItem* tempData;
                tempData->value = $1;
                $$ = tempData;
            }
            |   BOOLEAN_CONST {
                struct DataItem* tempData;
                tempData->value = $1;
                $$ = tempData;
            }
            |   REAL_CONST {
                struct DataItem* tempData;
                tempData->value = $1;
                $$ = tempData;
            }
            |   STR_CONST {
                Trace("STR_CONST");
            }
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

expression:     IDENTIFIER{
                Trace("id");
            }
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
            {
                Trace("test");
            }
            |   '~' expression
            {
                Trace("test");
            }
            |   expression AND expression
            |   expression OR expression
            |   IDENTIFIER '[' expression ']'
            {
                Trace("test");
            }
            |   '(' expression ')'
            {
                Trace("test");
            }
            |   '-' expression %prec UMINUS
            {
                Trace("test");
            }
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
                    {
                        Trace("test");
                    }
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
