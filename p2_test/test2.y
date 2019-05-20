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

int yylex();
void yyerror(string error_str);
vector<SymbolTable> stack;
SymbolTable SymbolList;
vector<string> id_arr;
DataItem* lookupAll(string s);

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
%type <type> data_type opt_func_type
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
            {
                DataItem* id = new DataItem();
                id->IdName=*$2;
                id->entries="module";
                int a=stack.back().insert(*$2,*id);
                // if(a)
                // {   cout << ("--------------------------------------------")<<endl;
                //     cout<<"pro_id insert successedfull!"<<endl;
                //     cout << ("--------------------------------------------")<<endl;
                // }
            }
            optional_var_con_declaration Procedure_dec
            {
                stack.back().Dump();
            }
             _BEGIN optional_statement END IDENTIFIER '.'
            {
                
                if(*$2!=*$10)
                    yyerror("End's id != Module's id\n");
            }
            ;

Procedure_dec:  PROCEDURE IDENTIFIER 
                {
                    SymbolTable temp;
                    stack.push_back(temp);
                }
                optional_arg_parentheses opt_func_type
                {
                    
                    DataItem* func_id = new DataItem();
                    func_id->IdName=*$2;
                    func_id->type=$5;
                    func_id->entries="Procedure";
                    int a=stack[0].insert(*$2,*func_id);
                    // if(a)
                    // {   cout << ("--------------------------------------------")<<endl;
                    //     cout<<"procedure_id insert successedfull!"<<endl;
                    //     cout << ("--------------------------------------------")<<endl;
                    // }
                }
                optional_var_con_declaration 
                _BEGIN optional_statement END IDENTIFIER ';'
                {
                    if(*$2!=*$11)
                        yyerror("End's id != Procedure's id");
                    stack.back().Dump();
                    stack.pop_back();
                } Procedure_dec
                |   PROCEDURE IDENTIFIER 
                {
                    SymbolTable temp;
                    stack.push_back(temp);
                }
                optional_arg_parentheses opt_func_type
                {
                    
                    DataItem* func_id = new DataItem();
                    func_id->IdName=*$2;
                    func_id->type=$5;
                    func_id->entries="Procedure";
                    int a=stack[0].insert(*$2,*func_id);
                    // if(a)
                    // {   cout << ("--------------------------------------------")<<endl;
                    //     cout<<"procedure_id insert successedfull!"<<endl;
                    //     cout << ("--------------------------------------------")<<endl;
                    // }
                }
                optional_var_con_declaration 
                _BEGIN optional_statement END IDENTIFIER ';'
                {
                    if(*$2!=*$11)
                        yyerror("End's id != Procedure's id");
                    stack.back().Dump();
                    stack.pop_back();
                }
                | 
                ;

opt_func_type: ':' data_type
            {
                $$=$2;
            }
            |
            {Trace("null");}
            ;

optional_var_con_declaration:  constants optional_var_con_declaration
                            |  variables optional_var_con_declaration
                            |   
                            ;

constants:  CONST IDENTIFIER '=' expression ';'
        {
            $4 -> IdName = *$2;
            $4 -> entries = "const";
            int a=stack.back().insert(*$2,*($4));
            // if(a){
            //     cout << ("--------------------------------------------")<<endl;
            //     cout<<"const insert successful!"<<endl;
            //     cout << ("--------------------------------------------")<<endl;
            // }
        }
        |   IDENTIFIER '=' expression ';' 
        {
            $3 -> IdName = *$1;
            $3 -> entries = "const";
            int a=stack.back().insert(*$1,*($3));
            // if(a){
            //     cout << ("--------------------------------------------")<<endl;
            //     cout<<"const insert successful!"<<endl;
            //     cout << ("--------------------------------------------")<<endl;
            // }
        }
        ;

variables:      VAR opt_IDENTIFIER ':' data_type ';'
            {
                for(int i=0;i<id_arr.size();i++){
                    DataItem* tempData = new DataItem();
                    tempData->IdName = id_arr[i];
                    tempData->type = $4;
                    tempData->entries = "variables";
                    int a=stack.back().insert(id_arr[i],*tempData);
                    // if(a)
                    // {   cout << ("--------------------------------------------")<<endl;
                    //     cout<<"variable insert successful!"<<endl;
                    //     cout << ("--------------------------------------------")<<endl;
                    // }
                }
                id_arr.clear();
            }
            |   IDENTIFIER ':' ARRAY '[' INT_CONST ',' INT_CONST ']' OF data_type ';'
            {
                Trace("array");
            }
            ;
                        
opt_IDENTIFIER:		IDENTIFIER ',' opt_IDENTIFIER
          {   
              string s=*$1;
              id_arr.push_back(s);
          }
	      |		IDENTIFIER
          {
              string s=*$1;
              id_arr.push_back(s);
          }
	      ;

optional_arg_parentheses: '(' optional_arguments ')'
                |
                ;

optional_arguments: IDENTIFIER ':' data_type
                {
                    DataItem* tempData=new DataItem();
                    tempData->IdName=*$1;
                    tempData->type=$3;
                    tempData->entries="argument";
                    int a=stack.back().insert(*$1,*tempData);
                    // if(a){
                    //     cout << ("--------------------------------------------")<<endl;
                    //     cout<<"argument insert successful!"<<endl;
                    //     cout << ("--------------------------------------------")<<endl;
                    // }
                }
                |   optional_arguments ',' IDENTIFIER ':' data_type
                {
                    DataItem* tempData=new DataItem();
                    tempData->IdName=*$3;
                    tempData->type=$5;
                    tempData->entries="argument";
                    int a=stack.back().insert(*$3,*tempData);
                    // if(a){
                    //     cout << ("--------------------------------------------")<<endl;
                    //     cout<<"argument insert successful!"<<endl;
                    //     cout << ("--------------------------------------------")<<endl;
                    // }
                }
                |   
                ;



data_type:      STRING { $$=STRING_type; }
            |   INTEGER { $$=INTEGER_type; }
            |   BOOLEAN {$$=BOOLEAN_type;}
            |   REAL {$$=REAL_type;}
            ;

const_value:    INT_CONST {
                DataItem* tempData = new DataItem();
                tempData->type = INTEGER_type;
                tempData->val = $1;
                $$ = tempData;
            }
            |   BOOLEAN_CONST {
                DataItem* tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = $1;
                $$ = tempData;
            }
            |   REAL_CONST {
                DataItem* tempData = new DataItem();
                tempData->type = REAL_type;
                tempData->dval = $1;
                $$ = tempData;
            }
            |   STR_CONST {
                DataItem* tempData = new DataItem();
                tempData->type = STRING_type;
                tempData->sval = ($1)->c_str();
                $$ = tempData;
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
                DataItem* tempData=lookupAll(*$1);
                if(tempData == NULL) yyerror("ERROR! undeclared");
                $$=tempData;
            }
            |   const_value
            |   function_invocation
            |   expression '*' expression
            {
                if($1->type != $3->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if($1->type==INTEGER_type)
                {
                    tempData->type=$1->type;
                    tempData->val=$1->val * $3->val;
                }else if($1->type==REAL_type)
                {
                    tempData->type=$1->type;
                    tempData->dval=$1->dval * $3->dval;
                }else{
                    yyerror("can't use the '*' operation");
                }
                // cout << "'*' successed!"<<endl;
                $$ = tempData;
            }
            |   expression '/' expression
            {
                if($1->type != $3->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if($1->type==INTEGER_type)
                {
                    tempData->type=$1->type;
                    tempData->val=$1->val / $3->val;
                }else if($1->type==REAL_type)
                {
                    tempData->type=$1->type;
                    tempData->dval=$1->dval / $3->dval;
                }else{
                    yyerror("can't use the '/' operation");
                }
                // cout << "'/' successed!"<<endl;
                $$ = tempData;
            }
            |   expression '+' expression
            {
                if($1->type != $3->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if($1->type==INTEGER_type)
                {
                    tempData->type=$1->type;
                    tempData->val=$1->val + $3->val;
                }else if($1->type==REAL_type)
                {
                    tempData->type=$1->type;
                    tempData->dval=$1->dval + $3->dval;
                }else{
                    yyerror("can't use the '*' operation");
                }
                // cout << "'+' successed!"<<endl;
                $$ = tempData;
            }
            |   expression '-' expression
            {
                if($1->type != $3->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if($1->type==INTEGER_type)
                {
                    tempData->type=$1->type;
                    tempData->val=$1->val - $3->val;
                }else if($1->type==REAL_type)
                {
                    tempData->type=$1->type;
                    tempData->dval=$1->dval - $3->dval;
                }else{
                    yyerror("can't use the '-' operation");
                }
                // cout << "'-' successed!"<<endl;
                $$ = tempData;
            }
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

conditional_statement:  IF '(' expression ')' THEN
                        {
                            SymbolTable tempData = stack.back();
                            stack.push_back(tempData);
                        }
                         optional_statement 
                        {
                            stack.back().Dump();
                            stack.pop_back();
                        }
                         ELSE 
                        {
                            SymbolTable tempData = stack.back();
                            stack.push_back(tempData);
                        }
                         optional_statement 
                         END ';'
                        {
                            stack.back().Dump();
                            stack.pop_back();
                        }
                        |   IF '(' expression ')' THEN
                        {
                            SymbolTable tempData = stack.back();
                            stack.push_back(tempData);
                        }
                         optional_statement END ';'
                        {
                            stack.back().Dump();
                            stack.pop_back();
                        }
                        ;

loop_statement: WHILE '(' expression ')' DO
                {
                    SymbolTable tempData = stack.back();
                    stack.push_back(tempData);
                }
                optional_statement END ';'
                {
                    stack.back().Dump();
                    stack.pop_back();
                }
                ;

optional_statement:    statement optional_statement
                    |  statement
	   	            ;

function_invocation:    IDENTIFIER '(' optional_comma_separated_expression ')'
                    {
                        DataItem* tempData=lookupAll(*$1);
                        Trace("IDENTIFIER '(' optional_comma_separated_expression ')'");
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

DataItem* lookupAll(string s) {
	for(int i=stack.size()-1;i>=0;i--){
		if(stack[i].lookup(s)){
            cout<<i<<endl;
			return stack[i].lookup(s);
		}
	}
    return NULL;
}

//  string s = "HelloWorld";        
//                 DataItem* temp=lookupAll(s);
//                 cout << temp->IdName <<endl;

int main(){
    SymbolTable global;
    stack.push_back(global);
    yyparse();
    // cout << ("\n--------------------------------------------\n\t\tSymbol Table");
    // cout << ("\n--------------------------------------------\n");
    // cout << ("Name\tType\tValue\t\tentries\n");
    
	return 0;	
}
