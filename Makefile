all: compiler
OBJS = parser.o \
	token.o  \
	codegen.o \
	corefn.o \
	main.o	 \
	TypeStream.o \



LLVMCONFIG = llvm-config-3.9
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic
LIBS = `$(LLVMCONFIG) --libs`



clean:
	$(RM) -rf parser.cpp parser.hpp compiler tokens.cpp *.output $(OBJS)

codegen.cpp: codegen.h node.h

parser.cpp: parser.y
	bison -d -o $@ $<

parser.hpp: parser.cpp

token.cpp: lex_analysis.lex parser.hpp
	flex -o $@ $<

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

compiler: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)
