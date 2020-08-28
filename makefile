# compiler and linker
CC := g++

# target binary program
TARGET := Run_me

# flags for C++ compiler
CXXFLAGS += -std=c++17

all: Run_me

# Run_me: XorShift256.cpp Run_me.cpp
Run_me: Run_me.cpp
	${CC} ${CXXFLAGS} $^ -o $@

clean:
	rm Run_me