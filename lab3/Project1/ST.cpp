#include<iostream> 
#include <list> 

#include <fstream> 
using namespace std;

class ST
{
	int size;
	list<string>* table;
public:
	ST(int size) {
		this->size = size;
		table = new list<string>[size];
	}
	void insertValue(string value) {
		if (checkIfExists(value) == false) {
			int index = hashFunction(value);
			table[index].push_back(value);
		}
	}
	bool checkIfExists(string value) {
		for (int i = 0; i < size; i++) {
			for (auto var : table[i])
				if (value == var)
					return true;
		}
		return false;
	}

	int hashFunction(string value) {
		int c = 0;
		for (int i = 0; i < value.size(); i++) {
			c += int(value[i]);
		}
		return c % size;
	}

	void showST() {
		ofstream stFile;
		stFile.open("ST.txt");
		stFile << "Hash with separate chaining" << endl;
		for (int i = 0; i < size; i++) {
			stFile << i;
			for (auto x : table[i])
				stFile << " --> " << x;
			stFile << endl;
		}
	}
};





//int main() {
//
//	ST st(10);
//	st.insertValue("Juliet");
//	st.insertValue("Erickson");
//	st.insertValue("Ericks");
//	st.insertValue("Index");
//	st.insertValue("i");
//	st.insertValue("ind");
//	st.insertValue("indir");
//
//	st.showST();
//
//	return 0;
//}
