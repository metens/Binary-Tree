#include <iostream>

class node{
	public:
		node(int input = 0); // default argument const.
		~node();
		node*& goLeft();
		node*& goRight();
		int getData();
		void setRight(node* &dest);
		void setLeft(node* &dest);
		void displayData() const;
	private:
		int data;
		node* left;
		node* right;
};
node::node(int input): data(input), left(0), right(0) {}
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
void node::setRight(node* &dest){
	right = dest;
}
void node::setLeft(node* &dest){
	left = dest;
}
void node::displayData() const{
	std::cout << data << " ";
}

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
tree::~tree(){
	if(root) removeAll(root);
}
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
int tree::create(int input){
	return create(root, input);
}
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
