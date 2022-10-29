// This file is the main function that implements
// the classes from the node header file. It creates the
// binary tree with the user input data.

#include "node.h"
using namespace std;

int main() {

	tree T;
	int input = 0;

	cout<<"Enter some data for tree (0 to stop): ";
	cin>>input;
	cin.ignore(100, '\n');

	T.create(input);

	while(input != 0){
		cout<<"Enter some data for tree (0 to stop): ";
		cin>>input;
		cin.ignore(100, '\n');

		T.create(input);
	}

	T.display();

	cout<<endl;

	return 0;
}
