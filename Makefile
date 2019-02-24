.PHONY : all

all : dicegen
dicegen : dicegen.cpp diceware_list.hpp
	g++ -std=c++14 -O3 -Wall dicegen.cpp -o dicegen