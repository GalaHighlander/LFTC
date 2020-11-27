#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Transition {
public: 
	string initState;
	string literal;
	string next;
	Transition(string init, string lit, string nex) {
		initState = init;
		literal = lit;
		next = nex;
	}
};