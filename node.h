// This header file has the node class and the tree class,
// along with their methods and implementations. The tree class
// uses the node class to create nodes and store them in a tree
// structure with respect to thier integer values.

#include <iostream>

// This is the node class which contains the methods and properties of
// each node in the binary tree data structure.
class node{
	public:
		node(int input = 0);					// default argument constructor 
		~node();											// destructor
		node*& goLeft();							// traverse left address pointer method
		node*& goRight();							// traverse right address pointer method
	// setters, getters, and display methods:
		int getData();
		void setRight(node* &dest);
		void setLeft(node* &dest);
		void displayData() const;
	private:
		int data;
		node* left;
		node* right;
};

// Constructor initializing all private data members to their null equivalents
node::node(int input): data(input), left(0), right(0) {}

// Destructor deletes both left and right pointers and sets them to null
node::~node(){
	if(left){
		delete left;
		left = NULL;
	}
	if(right){
		delete right;
		right = NULL;
	}
}

node*& node::goLeft(){
	return left;
}

node*& node::goRight(){
	return right;
}

int node::getData(){
	return data;
}

// Passing in the right destination node for the
// current node's right pointer to point to
void node::setRight(node* &dest){
	right = dest;
}

void node::setLeft(node* &dest){
	left = dest;
}

void node::displayData() const{
	std::cout << data << " ";
}

// This is the tree class that is reponsible for creating, adding,
// and removing each node.
class tree{
	public:
		tree();
		~tree();
		int create(int input);
		int create(node* &root, int input);
		int display();
		int display(node* root);
		int removeAll(node* &root);
	private:
		node* root;
};

tree::tree(): root(0) {}

// Destructor calls the remove all method
tree::~tree(){
	if(root) removeAll(root);
}

// Recursively goes through all nodes until the end of the tree
// is reached. Then delete the last node and make it null.
// This affect ripples all the way back recursively until all
// nodes are deleted and no data is left floating.
int tree::removeAll(node* &root){
	if(root != NULL){
		removeAll(root->goLeft());
		removeAll(root->goRight());
		delete root;
		root = NULL;
		return 1;
	}
	return 0;
}

// Wrapper function 
int tree::create(int input){
	return create(root, input);
}

// This create method compares each node's value with the 
// new incoming node's value. The greater value nodes will
// be stored to the right, and the smaller value nodes will
// be stored to the left, creating a tree structure.
int tree::create(node* &root, int input){
	if(root == NULL){
		root = new node(input);
		return 0;
	}
	if(root->getData() <= input) return create(root->goRight(), input);
	return create(root->goLeft(), input);
}

int tree::display(){
	if(root == NULL) return 0;
	return display(root);	
}

int tree::display(node* root){
	if(root == NULL) return 0;
	display(root->goLeft());
	root->displayData();
	return display(root->goRight());
}
