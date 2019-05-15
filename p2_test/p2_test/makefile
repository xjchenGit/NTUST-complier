a.out:y.tab.c lex.yy.c
	g++ y.tab.c lex.yy.c -ll -ly

lex.yy.c:modula.l
	flex modula.l

y.tab.c:test1.y
	bison -y -d test1.y

clean:
	-rm -f a.out
	-rm -f *.c
	-rm -f *.h
	-rm -f *.output
