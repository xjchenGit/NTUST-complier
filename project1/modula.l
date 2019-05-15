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
IDENTIFIERSs [A-Za-z]([0-9]|[A-Za-z])*
integer {digits}+
real [+-]?{integer}"\."{integer}([e][+-]{integer})?
str [\"]([A-Za-z0-9\n\t ]|([^\"]|[\"][\"]))*[\"]

%x COMMENTS

%%
","	{token(',');}
":"	{token(':');}
"\."	{token('.');}
";"	{token(';');}
"("	{token('(');}
")"	{token(')');}
"["	{token('[');}
"]"	{token(']');}
"{"	{token('{');}
"}"	{token('}');}
"+"	{token('+');}
"-"	{token('-');}
"*"	{token('*');}
"/"	{token('/');}
"%"	{token('%');}
"<"	{token('<');}
"<="	{token("<=");}
">="	{token(">=");}
">"	{token('>');}
"="	{token('=');}
"<>"	{token("<>");}
"&&"	{token("&&");}
"||"	{token("||");}
"~"	{token('~');}
":="	{token(":=");}

"array"	{token(ARRAY);}
"boolean"	{token(BOOLEAN);}  //
"begin"	{token(BEGIN);}
"break"	{token(BREAK);}
"char"	{token(CHAR);}  //
"case"	{token(CASE);}
"const"	{token(CONST);}
"continue"	{token(CONTINUE);}
"do"	{token(DO);}
"else"	{token(ELSE);}
"end"	{token(END);}
"exit"	{token(EXIT);}
"false"	{token(FALSE);}
"for"	{token(FOR);}
"fn"	{token(FN);}
"if"	{token(IF);}
"in"	{token(IN);}
"integer"	{token(INTEGER);}  //
"loop"	{token(LOOP);}
"module"	{token(MODULE);}
"print"	{token(PRINT);}
"println"	{token(PRINTLN);}
"procedure"	{token(PROCEDURE);}
"repeat"	{token(REPEAT);}
"return"	{token(RETURN);}
"real"	{token(REAL);}
"string"	{token(STRING);}
"record"	{token(RECORD);}
"then"	{token(THEN);}
"ture"	{token(TURE);}
"type"	{token(TYPE);}
"use"	{token(USE);}
"util"	{token(UTIL);}
"var"	{token(VAR);}
"while"	{token(WHILE);}

[/][/]([a-zA-Z \t])* {
		LIST;
		}

{IDENTIFIERSs} {
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

}
{integer} {
	tokenInteger("integer",atoi(yytext));
}

{real} {
	tokenString("real",yytext);
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
