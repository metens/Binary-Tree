#include "node.h"
using namespace std;

int main() {

	tree T;
	int input = 0;

	cout<<"Enter some data for tree: ";
	cin>>input;
	cin.ignore(100, '\n');

	T.create(input);

	while(input != 0){
		cout<<"Enter some data for tree: ";
		cin>>input;
		cin.ignore(100, '\n');

		T.create(input);
	}

	T.display();

	cout<<endl;

	return 0;
}
