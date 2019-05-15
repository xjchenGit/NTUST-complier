%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
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
","	{token(',');return yytext[0];}
":"	{token(':');return yytext[0];}
"\."	{token('\.');return yytext[0];}
";"	{token(';');return yytext[0];}
"("	{token('(');return yytext[0];}
")"	{token(')');return yytext[0];}
"["	{token('[');return yytext[0];}
"]"	{token(']');return yytext[0];}
"{"	{token('{');return yytext[0];}
"}"	{token('}');return yytext[0];}
"+"	{token('+');return yytext[0];}
"-"	{token('-');return yytext[0];}
"*"	{token('*');return yytext[0];}
"/"	{token('/');return yytext[0];}
"%"	{token('%');return yytext[0];}
"<"	{token('<');return yytext[0];}
">"	{token('>');return yytext[0];}
"<="	{token('<=');return LE_EQ;}
">="	{token('>=');return GR_EQ;}
"~"	{token('~');return yytext[0];}
"="	{token('=');return yytext[0];}
"<>"	{token('<>');return NEQ;}
"&&"	{token('&&');return AND;}
"||"	{token('||');return OR;}
":="	{token(':=');return EQ;}

"array"	{token(ARRAY);return ARRAY;}
"boolean"	{token(BOOLEAN);return BOOLEAN;}
"begin"	{token(T_BEGIN);return T_BEGIN;}
"break"	{token(BREAK);return BREAK;}
"char"	{token(CHAR);return CHAR;}
"case"	{token(CASE);return CASE;}
"const"	{token(CONST);return CONST;}
"continue"	{token(CONTINUE);return CONTINUE;}
"do"	{token(DO);return DO;}
"else"	{token(ELSE);return ELSE;}
"end"	{token(END);return END;}
"exit"	{token(EXIT);return EXIT;}
"false"	{token(FALSE);return FALSE;}
"for"	{token(FOR);return FOR;}
"fn"	{token(FN);return FN;}
"if"	{token(IF);return IF;}
"in"	{token(IN);return IN;}
"integer"	{token(INTEGER);return INTEGER;}
"loop"	{token(LOOP);return LOOP;}
"module"	{token(MODULE);return MODULE;}
"print"	{token(PRINT);return PRINT;}
"println"	{token(PRINTLN);return PRINTLN;}
"procedure"	{token(PROCEDURE);return PROCEDURE;}
"repeat"	{token(REPEAT);return REPEAT;}
"return"	{token(RETURN);return(RETURN);}
"real"	{token(REAL);return REAL;}
"string"	{token(STRING);return STRING;}
"record"	{token(RECORD);return RECORD;}
"then"	{token(THEN);return THEN;}
"ture"	{token(TURE);return TURE;}
"type"	{token(TYPE);return TYPE;}
"use"	{token(USE);return USE;}
"util"	{token(UTIL);return UTIL;}
"var"	{token(VAR);return VAR;}
"while"	{token(WHILE);return WHILE;}

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
		return IDENTIFIER;
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
