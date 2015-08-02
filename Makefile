CPP = g++ -std=c++11 -I $GTEST_HOME/include -L $GTEST_HOME/lib -lgtest -lgtest_main -lpthread
SRC = object.cpp lispString.cpp number.cpp symbolsList.cpp lispFunctions.cpp doublet.cpp
OBJ = $(SRC:.cpp = .o)

all: clean lispInterpreter test

lispInterpreter: main.o $(OBJ)
	$(CPP) -o $@ $^

test: test.o $(OBJ)
	$(CPP) -o $@ $^

.PHONY: clean
clean:
	rm -rf *.o lispInterpreter test/test
