CC=g++
CXXFLAGS=-c -Wall -Werror -Wextra -std=c++11
SOURCES=main.cpp
EXECUTABLE=main.exe

all:
	g++ main.cpp -o main.exe -Wall -Werror -Wextra -std=c++11