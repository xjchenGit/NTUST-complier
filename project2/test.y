%{
#include <iostream>
using namespace std;
}%

%union{
    int val;
    double dval;
    string* sval;
    int type;
    Datata* idD;
};

%token AND OR EQ LE_EQ GR_EQ NEQ
%token ARRAY BOOLEAN BEGIN BREAK CHAR CASE CONST CONTINUE DO ELSE END EXIT FALSE FOR FN IF IN INTEGER LOOP MODULE PRINT PRINTLN PROCEDURE REPEAT RETURN REAL STRING RECORD THEN TURE TYPE USE UTIL VAR WHILE

%token <sval> IDENTIFIER
%token <val> INT_INTEGER
%token <dval> REAL_CONST
%token <sval> STR_CONST
%toekn <bval> BOOL_CONST

%start program

/*precedence*/
%left '-'
%left '*' '/'
%left '+' '-'
%left '<' LE_EQ '=' GR_EQ '>' NEQ
%left '~'
%left AND 
%left OR
%nonassoc UMINUS

%%
program:    identifier semi
            {
                Trace("Reducing to program\n");
            }
            ;
    
%%


%type  <val> 
value_declaration 
program 
primary_expression 
type_specifier 
declarator_list 
declarator


%type <int_type> number_declaration