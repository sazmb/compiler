 bup: o_files/lexer.o o_files/parser.o o_files/tree.o o_files/symbolTable.o o_files/genCode.o o_files/main.o
	cc -g -o bup o_files/lexer.o o_files/parser.o o_files/tree.o o_files/symbolTable.o o_files/genCode.o o_files/main.o
o_files/lexer.o: lexer.c header_files/parser.h header_files/def.h
	cc -g -c lexer.c -o o_files/lexer.o
o_files/parser.o: parser.c header_files/symbolTable.h
	cc -g -c parser.c -o o_files/parser.o
o_files/tree.o: tree.c header_files/def.h
	cc -g -c tree.c -o o_files/tree.o
lexer.c: lexer.lex parser.y header_files/parser.h parser.c header_files/def.h
	flex -o lexer.c lexer.lex
header_files/parser.h: parser.y header_files/def.h
	bison -d -v -o parser.c parser.y
o_files/genCode.o: genCode.c header_files/genCode.h
	cc -g -c genCode.c -o o_files/genCode.o
o_files/main.o: main.c header_files/def.h header_files/symbolTable.h header_files/genCode.h
	cc -g -c main.c -o o_files/main.o
o_files/symbolTable.o: symbolTable.c header_files/symbolTable.h
	cc -g -c symbolTable.c -o o_files/symbolTable.o









