a.out:y.tab.cpp lex.yy.cpp
	g++ -std=c++11 -Wno-deprecated-register Symbol.hpp y.tab.cpp -o parser -ll -ly

lex.yy.cpp:modula.l
	flex -o lex.yy.cpp modula.l

y.tab.cpp:test2.y
	yacc -y -v -d test2.y -o y.tab.cpp

clean:
	-rm -f a.out
	-rm -f *.cpp
	-rm -f y.tab.hpp
	-rm -f y.output
	-rm -f parser
