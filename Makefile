CXX = clang++
CXXFLAGS = -ggdb

BIN = main

all: $(BIN)

main: main.cpp
	${CXX} $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BIN)

.PHONY: all  clean main
