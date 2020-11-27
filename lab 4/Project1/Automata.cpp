#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include "Transition.cpp"

using namespace std;

class Automata {


public: 
	string initState;
	vector<string> states;
	vector<string> finStates;
	vector<string> alphabet;
	vector<Transition> transitionList;


	void readFA() {
		ifstream file("FA.txt");
		string statesLine;


		getline(file, statesLine);

		size_t position = 0;
		string separator = ",";

		std::string token;
		while ((position = statesLine.find(separator)) != std::string::npos) {
			token = statesLine.substr(0, position);
			states.push_back(token);
			statesLine.erase(0, position + separator.length());
		}
		states.push_back(statesLine);

		position = 0;
		string alphabetLine;
		getline(file, alphabetLine);
		while ((position = statesLine.find(separator)) != std::string::npos) {
			token = alphabetLine.substr(0, position);
			alphabet.push_back(token);
			alphabetLine.erase(0, position + separator.length());
		}
		alphabet.push_back(alphabetLine);


		getline(file, initState);
		string finalStat;
		getline(file, finalStat);
		position = 0;
		while ((position = finalStat.find(separator)) != std::string::npos) {
			token = finalStat.substr(0, position);
			finStates.push_back(token);
			finalStat.erase(0, position + separator.length());
		}
		finStates.push_back(finalStat);

		string trans;
		while (getline(file, trans)) {
			vector<string> transList;
			position = 0;
			while ((position = trans.find(separator)) != std::string::npos) {
				token = trans.substr(0, position);
				transList.push_back(token);
				trans.erase(0, position + separator.length());
			}
			transList.push_back(trans);

			Transition t(transList[0], transList[1], transList[2]);
			transitionList.push_back(t);
		}
	}

	bool IsDFA() {
		for (int i = 0; i < transitionList.size(); i++)
			for (int j = i + 1; j < transitionList.size(); j++)
				if (transitionList[i].initState == transitionList[j].initState && transitionList[i].literal == transitionList[j].literal)
					return false;
		return true;
	}

	void checkSeq(string sequence) {
		string sq = "";
		sq += sequence[0];

		string nextState;
		for(Transition tr:this -> transitionList)
			if (tr.initState == this->initState && sq == tr.literal) {
				nextState = tr.next;
				break;
			}
		for (int i = 1; i < sequence.size(); i++)
		{
			sq = "";
			sq += sequence[i];

			for(Transition tr:this -> transitionList)
				if (tr.initState == nextState && sq == tr.literal)
				{
					nextState = tr.next;
					break;
				}
		}

		for(string s :this -> finStates)
			if (s == nextState)
			{
				cout << "Correct sequence\n";
				return;
			}
		cout << "Wrong sequence";
	}
};



