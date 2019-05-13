%{
#include <iostream>
using namespace std;
%}

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

//type declare for non-terminal symbols
%type <type> var_type

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

//  type
var_type:       INTEGER
            |   BOOLEAN
            |   STRING
            |   
            ;

// Syntactic Definitions

/* 
    Constants and Variable Definitions
*/

optional_var_declaration:   
            |   
            ;

constants:  CONST IDENTIFIER '=' expression //constant_exp
            ;

variables:      VAR IDENTIFIER ':' var_type ';'
            |   
            |   IDENTIFIER
            ;

statement:      IDENTIFIER EQ expression ';'
            |   IDENTIFIER '[' expression ']' EQ expression';' //integer-expression
            |   PRINT expression ';'
            |   PRINTLN expression ';'
            |   READ IDENTIFIER ';'   //要往前面加一个READ的token
            |   RETURN ';'
            |   RETURN expression ';'
            |   conditional
            |   loop
            |   function_invocation
            ;

function_invocation:    IDENTIFIER '(' expression ')' ';' //comma-separated expressopns
            ;

conditional:    IF '(' expression ')' THEN //boolean_expre
            |   IF '(' expression ')' 
            ;

/*
    Program Units
*/


expression:     IDENTIFIER
            |   '-' expression %prec UMINUS
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
            |   IDENTIFIER '[' expression ']'   //数组 integer_expression
            |   IDENTIFIER '(' expression ')'   //comma-separed expression
            ;

/*
    Semantic Definition
*/

%%


%type  <val> 
value_declaration 
program 
primary_expression 
type_specifier 
declarator_list 
declarator


%type <int_type> number_declaration