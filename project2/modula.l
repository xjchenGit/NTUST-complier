%{
#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENG 256
#define LIST	strcat(buf,yytext)
#define token(t) {LIST;printf("<%s>\n",#t);}
#define tokenInteger(t,i) {LIST;printf("<%s:%d>\n",t,i);}
#define tokenString(t,s) {LIST;printf("<%s:%s>\n",t,s);}
int linenum = 1;
char buf[MAX_LINE_LENG];
char table[256][256];
int table_index = 0;
%}

digits [0-9]
letter [A-Za-z]
identifiers [A-Za-z]([0-9]|[A-Za-z])*
integer {digits}+
real [+-]?{integer}"\."{integer}([e][+-]{integer})?
str [\"]([A-Za-z0-9\n\t ]|([^\"]|[\"][\"]))*[\"]

%x COMMENTS

%%
","	{return(',');}
":"	{return(':');}
"\."	{return('.');}
";"	{return(';');}
"("	{return('(');}
")"	{return(')');}
"["	{return('[');}
"]"	{return(']');}
"{"	{return('{');}
"}"	{return('}');}
"+"	{return('+');}
"-"	{return('-');}
"*"	{return('*');}
"/"	{return('/');}
"%"	{return('%');}
"<"	{return('<');}
"<="	{return("LE_EQ");}
">="	{return("GR_EQ");}
">"	{return('>');}
"="	{return('=');}
"<>"	{return("NEQ");}
"&&"	{return("AND");}
"||"	{return("OR");}
"~"	{return('~');}
":="	{return("EQ");}

"array"	{return(ARRAY);}
"boolean"	{return(BOOLEAN);}
"begin"	{return(BEGIN);}
"break"	{return(BREAK);}
"char"	{return(CHAR);}
"case"	{return(CASE);}
"const"	{return(CONST);}
"continue"	{return(CONTINUE);}
"do"	{return(DO);}
"else"	{return(ELSE);}
"end"	{return(END);}
"exit"	{return(EXIT);}
"false"	{return(FALSE);}
"for"	{return(FOR);}
"fn"	{return(FN);}
"if"	{return(IF);}
"in"	{return(IN);}
"integer"	{return(INTEGER);}
"loop"	{return(LOOP);}
"module"	{return(MODULE);}
"print"	{return(PRINT);}
"println"	{return(PRINTLN);}
"procedure"	{return(PROCEDURE);}
"repeat"	{return(REPEAT);}
"return"	{return(RETURN);}
"real"	{return(REAL);}
"string"	{return(STRING);}
"record"	{return(RECORD);}
"then"	{return(THEN);}
"ture"	{return(TURE);}
"type"	{return(TYPE);}
"use"	{return(USE);}
"util"	{return(UTIL);}
"var"	{return(VAR);}
"while"	{return(WHILE);}

[/][/]([a-zA-Z \t])* {
		LIST;
		}

{identifiers} {
	tokenString("id",yytext);
	int lookup = 0;
	for(int i = 0; i < table_index; i++){
		if(!strcmp(table[i],yytext)){
			lookup = 1;
			break;
		}

	}
	if(!lookup){
		strcpy(table[table_index],yytext);
		table_index++;
	}
	return IDENTIFIERS;
}
{integer} {
	tokenInteger("integer",atoi(yytext));
	return INT_CONST;
}

{real} {
	tokenString("real",yytext);
	return REAL_CONST;
}

{str} {
	int i=1;
	char num[256];
        int num_idx = 0;
	while(yytext[i]!='\0'){
		if(yytext[i]=='\"'&&yytext[i+1]=='\"'){
			num[num_idx] = yytext[i];
			i+=2;
			num_idx++;
		}else if(yytext[i]=='\"'&&yytext[i+1]=='\0')
		{
			break;
		}
		else{
			num[num_idx] = yytext[i];
			i++;
			num_idx++;
		}
	}
	num[num_idx] = '\0';
	tokenString("str",num);
	return STR_CONST;
}

"(*" {
        LIST;
        BEGIN COMMENTS;
}

<COMMENTS>\n {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
}
<COMMENTS>. {
		LIST;

}
<COMMENTS>"*)" {
        LIST;
        BEGIN INITIAL;
}


\n {
	LIST;
	printf("%d:%s",linenum,buf);
	linenum++;
	buf[0] = '\0';
	}

[ \t]*	{LIST;}

.	{
		LIST;
		printf("%d:%s\n",linenum,buf);
		printf("bad character:%s\n",yytext);
		exit(-1);
	}
%%

int yywrap(){
	return 1;
}

int main(){
	yylex();
	printf("\nSymbol Table: \n");
	for(int i = 0; i < table_index; i++)
		printf("%s\n",table[i]);
	return 0;	
}
