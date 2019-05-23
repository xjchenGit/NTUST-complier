%{
#include <iostream>
#include <stdio.h>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "Symbol.hpp"
#include "lex.yy.cpp"
using namespace std;
#define TRACE_FLAG 1
#define Trace(t) if (TRACE_FLAG) cout << "TRACE => " << t <<endl;

string outName;
ofstream out;

int yylex();
void yyerror(string error_str);
vector<SymbolTable> stack;
SymbolTable SymbolList;
vector<string> id_arr;
int args_num=0;
DataItem* lookupAll(string s);
DataItem* lookupAllAddress(string s);

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
%token OF
%token <s_val> IDENTIFIER
%token <_val> INT_CONST
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
                out << "class " << *$2 << endl;
                out << "{" << endl;
                outName=*$2;

                DataItem* id = new DataItem();
                id->IdName=*$2;
                id->entries="module";
                int a=stack.back().insert(*$2,*id);
            }
            optional_var_con_declaration Procedure_dec_list
            {
                stack.back().Dump();
                out  << "\tmethod public static void main(java.lang.String[])\n" << "\tmax_stack 15\n" << "\tmax_locals 15\n\t{\n";

            }
             _BEGIN optional_statement 
             {
                 out << "\t\treturn\n";
                 out << "\t}";
             }
             END IDENTIFIER '.'
            {
                out << "\n}\n";

                stack.back().Dump();
                if(*$2!=*$11)
                    yyerror("End's id != Module's id\n");
            }
            ;
Procedure_dec_list:Procedure_dec_list Procedure_dec 
                | Procedure_dec
                |
                ;

Procedure_dec:  PROCEDURE IDENTIFIER 
                {
                    SymbolTable temp;
                    stack.push_back(temp);
                }
                optional_arg_parentheses opt_func_type
                {
                    out << "\tmethod public static ";
                        out << "int ";
                        //out << "void ";后期需要补充
                    out << *$2 + "(";
                    for (int i = 0; i < args_num; i++) {
                        if(i!=0) out << ",";
                        out << "int";
                    }
                    out << ")\n" << "\tmax_stack 15\n" << "\tmax_locals 15\n\t{\n";
                    args_num=0;

                    DataItem* func_id = new DataItem();
                    func_id->IdName=*$2;
                    func_id->type=$5;
                    func_id->entries="Procedure";
                    int a=stack[0].insert(*$2,*func_id);
                }
                optional_var_con_declaration 
                _BEGIN optional_statement END IDENTIFIER ';'
                {
                    out << "\t}\n";

                    if(*$2!=*$11)
                        yyerror("End's id != Procedure's id");
                    stack.back().Dump();
                    cout<<stack.size()<<endl;
                    stack.pop_back();
                    cout <<stack.size()<<endl;
                } 
                ;

opt_func_type: ':' data_type{$$=$2;}
            |
            {Trace("null");}
            ;

optional_var_con_declaration:  constants optional_var_con_declaration
                            |  VAR variables 
                            |   
                            ;

constants:  CONST IDENTIFIER '=' expression ';'
        {
            $4 -> IdName = *$2;
            $4 -> entries = "const";
            int a=stack.back().insert(*$2,*($4));
            if($4->type==INTEGER_type)
                out << "\tfield static int "<<*$2<<" = "<<$4->val<<"\n";
        }
        |   IDENTIFIER '=' expression ';' 
        {
            $3 -> IdName = *$1;
            $3 -> entries = "const";
            int a=stack.back().insert(*$1,*($3));
            if($3->type==INTEGER_type)
                out << "\tfield static int "<<*$1<<" = "<<$3->val<<"\n";
        }
        ;

variables:   opt_IDENTIFIER ':' data_type ';' variables
            {
                for(int i=0;i<id_arr.size();i++){
                    DataItem* tempData = new DataItem();
                    tempData->IdName = id_arr[i];
                    tempData->type = $3;
                    tempData->entries = "variables";
                    int a=stack.back().insert(id_arr[i],*tempData);
                    if($3==INTEGER_type)
                        out << "\tfield static int "<<id_arr[i]<<"\n";
                }
                id_arr.clear();
            }
            | opt_IDENTIFIER ':' data_type ';'
            {
                for(int i=0;i<id_arr.size();i++){
                    DataItem* tempData = new DataItem();
                    tempData->IdName = id_arr[i];
                    tempData->type = $3;
                    tempData->entries = "variables";
                    int a=stack.back().insert(id_arr[i],*tempData);
                    if($3==INTEGER_type)
                        out << "\tfield static int "<<id_arr[i]<<"\n";
                }
                id_arr.clear();
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
          |
	      ;

optional_arg_parentheses: '(' optional_arguments ')'
                |
                ;

optional_arguments: IDENTIFIER ':' data_type
                {
                    args_num++;
                    DataItem* tempData=new DataItem();
                    tempData->IdName=*$1;
                    tempData->type=$3;
                    tempData->entries="argument";
                    int a=stack.back().insert(*$1,*tempData);
                }
                |   optional_arguments ',' IDENTIFIER ':' data_type
                {
                    args_num++;
                    DataItem* tempData=new DataItem();
                    tempData->IdName=*$3;
                    tempData->type=$5;
                    tempData->entries="argument";
                    int a=stack.back().insert(*$3,*tempData);
                }
                |   
                ;

data_type:      STRING { $$=STRING_type; }
            |   INTEGER { $$=INTEGER_type; }
            |   BOOLEAN {$$=BOOLEAN_type;}
            ;

const_value:    STR_CONST {
                DataItem* tempData = new DataItem();
                tempData->type = STRING_type;
                tempData->sval = ($1)->c_str();
                $$ = tempData;
            }    
            |   INT_CONST {
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
            ;

statement:      IDENTIFIER EQ expression ';'
            {
                DataItem *tempData=lookupAllAddress(*$1);
                if(tempData == NULL) yyerror("ERROR! undeclared");
                if($3->type==INTEGER_type)
                {
                    tempData->val=$3->val;
                }else if($3->type==BOOLEAN_type)
                {
                    tempData->bval=$3->bval;
                }
                stack.back().Dump();
                if(tempData->type==INTEGER_type||tempData->type==BOOLEAN_type){
                    if(stack.size()==1)
                        out << "\t\tputstatic int " << outName << "." << *$1 << "\n";
                }
            }
            |   {
                    out << "\t\tgetstatic java.io.PrintStream java.lang.System.out\n";
                }
                PRINT expression ';'
                {
                    if($3->type==INTEGER_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.print(int)\n";
                    }else if($3->type==STRING_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                    }
                }
            |   {
                    out << "\t\tgetstatic java.io.PrintStream java.lang.System.out\n";
                }
                PRINTLN expression ';'
                {
                    if($3->type==INTEGER_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.println(int)\n";
                    }else if($3->type==STRING_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n";
                    }
                }
            |   RETURN ';'
            {
                out << "\treturn\n";
            }
            |   RETURN expression ';'
            {
                out << "\t\tireturn\n";
            }
	        |	expression ';'
            |   conditional_statement
            |   loop_statement
            ;

expression:     IDENTIFIER
            {  
                DataItem *tempData=lookupAll(*$1);
                if(tempData == NULL) yyerror("ERROR! undeclared");
                $$=tempData;

                // if(stack.size()!=1 && tempData->entries==const){

                // }
                if(stack.size()>1 && tempData->entries=="const")
                {
                    out<<"hhhhh";
                }else if(tempData->type==INTEGER_type || tempData->type==BOOLEAN_type)
                {
                    if(!stack.back().lookup(*$1) || stack.size()==1){
                        out << "\t\tgetstatic int " << outName << "." << *$1 << "\n";
                    }else{
                        int a=stack.back().getIndex(*$1);
                        out << "\t\tiload " << a << "\n";
                    }
                }
            }
            |   const_value
            {
                if(stack.size()!=1){
                    if($1->type==INTEGER_type)
                        out<<"\t\tsipush "<<$1->val<<"\n";
                    else if($1->type==STRING_type)
                        out<<"\t\tldc "<<$1->sval<<"\n";
                }
                $$ = $1;
            }
            |   function_invocation
            |   expression '*' expression
            {
                if($1->type != $3->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if($1->type==INTEGER_type)
                {
                    tempData->type=$1->type;
                    tempData->val=$1->val * $3->val;
                }else{
                    yyerror("can't use the '*' operation");
                }
                $$ = tempData;
                if($1->type == INTEGER_type)
                    out<<"\t\timul\n";
            }
            |   expression '/' expression
            {
                if($1->type != $3->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if($1->type==INTEGER_type)
                {
                    tempData->type=$1->type;
                    tempData->val=$1->val / $3->val;
                }else{
                    yyerror("can't use the '/' operation");
                }
                $$ = tempData;
                if($1->type == INTEGER_type)
                    out<<"\t\tidiv\n";
            }
            |   expression '+' expression
            {
                if($1->type != $3->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if($1->type==INTEGER_type)
                {
                    tempData->type=$1->type;
                    tempData->val=$1->val + $3->val;
                }else{
                    yyerror("can't use the '*' operation");
                }
                // cout << "'+' successed!"<<endl;
                $$ = tempData;
                if($1->type == INTEGER_type)
                    out<<"\t\tiadd\n";
            }
            |   expression '-' expression
            {
                if($1->type != $3->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if($1->type==INTEGER_type)
                {
                    tempData->type=$1->type;
                    tempData->val=$1->val - $3->val;
                }else{
                    yyerror("can't use the '-' operation");
                }
                // cout << "'-' successed!"<<endl;
                $$ = tempData;
                if($1->type == INTEGER_type)
                    out<<"\t\tisub\n";
            }
            |   expression '<' expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ($1->val <$3->val);
                $$ = tempData;

                out << "\t\tisub\n";
                // int lb1 = lm.getLable();
                // int lb2 = lm.getLable();
                // out << "\t\tiflt L" << "\n" << "\t\ticonst_0\n" << "\t\tgoto L" << "\n";
                // out << "\tL" << ":\n" << "\t\ticonst_1\n" << "\tL" << ":\n";
            }
            |   expression '>' expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ($1->val > $3->val);
                $$ = tempData;
                out << "\t\tisub\n";
                // int lb1 = lm.getLable();
                // int lb2 = lm.getLable();
                // out << "\t\tifgt L"  << "\n" << "\t\ticonst_0\n" << "\t\tgoto L"  << "\n";
                // out << "\tL"  << ":\n" << "\t\ticonst_1\n" << "\tL"  << ":\n";
            }
            |   expression '=' expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ($1->val == $3->val);
                $$ = tempData;
                out << "\t\tisub\n";
                // int lb1 = lm.getLable();
                // int lb2 = lm.getLable();
                // out << "\t\tifeq L"  << "\n" << "\t\ticonst_0\n" << "\t\tgoto L"  << "\n";
                // out << "\tL"  << ":\n" << "\t\ticonst_1\n" << "\tL"  << ":\n";
            }
            |   expression LE_EQ expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ($1->val <= $3->val);
                $$ = tempData;
                out << "\t\tisub\n";
                // int lb1 = lm.getLable();
                // int lb2 = lm.getLable();
                // out << "\t\tifle L"  << "\n" << "\t\ticonst_0\n" << "\t\tgoto L"  << "\n";
                // out << "\tL"  << ":\n" << "\t\ticonst_1\n" << "\tL"  << ":\n";
            }
            |   expression GR_EQ expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ($1->val >= $3->val);
                $$ = tempData;
                out << "\t\tisub\n";
                // int lb1 = lm.getLable();
                // int lb2 = lm.getLable();
                // out << "\t\tifge L" <<  "\n" << "\t\ticonst_0\n" << "\t\tgoto L" <<  "\n";
                // out << "\tL" <<  ":\n" << "\t\ticonst_1\n" << "\tL" <<  ":\n";
            }
            |   NEQ expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = (!$2->bval);
                $$ = tempData;
                out << "\t\tisub\n";
                // int lb1 = lm.getLable();
                // int lb2 = lm.getLable();
                // out << "\t\tifne L" <<  "\n" << "\t\ticonst_0\n" << "\t\tgoto L" <<  "\n";
                // out << "\tL" <<  ":\n" << "\t\ticonst_1\n" << "\tL" <<  ":\n";
            }
            |   '~' expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = INTEGER_type;
                tempData->val = ~($2->val);
                $$ = tempData;
                if($2->type == INTEGER_type)
                    out<<"ixor\n";
            }
            |   expression AND expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ($1->bval && $3->bval);
                $$ = tempData;
                if($1->type == INTEGER_type)
                    out<<"iand\n";
            }
            |   expression OR expression
            {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ($1->bval || $3->bval);
                $$ = tempData;
                if($1->type == INTEGER_type)
                    out<<"ior\n";
            }
            |   '(' expression ')'
            {
                $$=$2;
            }
            |   '-' expression %prec UMINUS{
                DataItem *tempData = new DataItem();
                tempData->type=INTEGER_type;
                tempData->val = -($2->val);
                $$=tempData;
                out<<"\t\tineg\n";
            }
            ;

conditional_statement:  IF '(' expression ')' THEN
                        {
                            // out << "\t\tifeq L" << "\n";
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
                            // out << "\t\tgoto L" << "\n";
	                        // out << "\tL" << ":\n";
                            SymbolTable tempData = stack.back();
                            stack.push_back(tempData);
                        }
                         optional_statement 
                         END ';'
                        {
                            // out << "\tL" << ":\n";
                            stack.back().Dump();
                            stack.pop_back();
                        }
                        |   IF '(' expression ')' THEN
                        {
                            // out << "\t\tifeq L" << "\n";
                            SymbolTable tempData = stack.back();
                            stack.push_back(tempData);
                        }
                         optional_statement END ';'
                        {
                            // out << "\nL" << lm.takeLabel(0) << ":\n";
                            // out << "\tL" << ":\n";
                            stack.back().Dump();
                            // stack.pop_back();
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
                    // out << "\t\tgoto L" << "\n";		// goto Lbegin
	                // out << "\t\nL" << ":\n";
                }
                ;

optional_statement:    statement optional_statement
                    |  statement
	   	            ;

function_invocation:    IDENTIFIER '(' optional_comma_separated_expression ')'
                    {
                        DataItem* tempData=lookupAll(*$1);
                        Trace("IDENTIFIER '(' optional_comma_separated_expression ')'");
                        out << "\t\tinvokestatic ";
                        out << "int ";
                        //out << "void ";后期需要补充
                        out << outName + "." + *$1 + "(";
                        for (int i = 0; i < args_num; i++) {
                            if(i!=0) out << ",";
                            out << "int";
                        }
                        out << ")\n";
                        args_num=0;
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
			return stack[i].lookup(s);
		}
	}
}

DataItem* lookupAllAddress(string s) {
    for(int i=stack.size()-1;i>=0;i--){
		if(stack[i].lookupAddress(s)){
			return stack[i].lookupAddress(s);
		}
	}
}

int main(int argc, char *argv[]){
    SymbolTable global;
    stack.push_back(global);
	
	// open input file and check exist
    yyin = fopen(argv[1], "r");
	if(!yyin){
		cerr << "[Error] File not found!" << endl;
		exit(1);	
	}

	string source = string(argv[1]);
	size_t found = source.rfind("/");
	size_t foundDot = source.rfind(".ru");
	outName = source.substr(found+1, foundDot - found - 1);
	out.open(outName + ".jasm");
    if (yyparse() == 1)
    {
        yyerror("[Error] Parsing error!");
    }

    // DataItem *temp=new DataItem();
    // string s="abc";
    // temp->IdName=s;
    
    // int a=stack[0].insert(s,*temp);
    // if(a)
    //     cout << "insert successed!!" <<endl;

    // DataItem *temp2=lookupAll(s);

    // cout << temp2->IdName <<endl;  

	return 0;	
}
