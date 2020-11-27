#include "Automata.cpp"

int main()
{
	Automata a;
	a.readFA();
	int i;
	for (i = 0; i < a.states.size(); i++)
	{
		cout << a.states[i] << " ";
	}
	cout << endl;

	for (i = 0; i < a.alphabet.size(); i++)
	{
		cout << a.alphabet[i] << " ";
	}
	cout << endl;
	for (i = 0; i < a.transitionList.size(); i++)
	{
		cout << "Trans:" << i + 1 << ": \n";
		cout << a.transitionList[i].initState << " " << a.transitionList[i].literal << " " << a.transitionList[i].next << "\n\n";
	}

	cout << "init: " << a.initState;
	cout << endl;
	cout << "fin: " << a.finStates[0];
	cout << endl;


	bool dfa = a.IsDFA();
	if (dfa == 1)
	{
		cout << "Is dfa";
	}
	else if (dfa == 0)
	{
		cout << "Is not dfa";
	}
	if (dfa == 1)
	{
		string c;
		cin >> c;
		a.checkSeq(c);
	}
	return 0;
}