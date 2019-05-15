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

%token <sval> IDENTIFIERS
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
program:    IDENTIFIERS semi
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

constants:  CONST IDENTIFIERS '=' expression //constant_exp
            ;

variables:      VAR IDENTIFIERS ':' var_type ';'
            |   
            |   IDENTIFIERS
            ;

statement:      IDENTIFIERS EQ expression ';'
            |   IDENTIFIERS '[' expression ']' EQ expression';' //integer-expression
            |   PRINT expression ';'
            |   PRINTLN expression ';'
            |   READ IDENTIFIERS ';'   //要往前面加一个READ的token
            |   RETURN ';'
            |   RETURN expression ';'
            |   conditional
            |   loop
            |   function_invocation
            ;

function_invocation:    IDENTIFIERS '(' expression ')' ';' //comma-separated expressopns
            ;

conditional:    IF '(' expression ')' THEN //boolean_expre
            |   IF '(' expression ')' 
            ;

/*
    Program Units
*/


expression:     IDENTIFIERS
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
            |   IDENTIFIERS '[' expression ']'   //数组 integer_expression
            |   IDENTIFIERS '(' expression ')'   //comma-separed expression
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