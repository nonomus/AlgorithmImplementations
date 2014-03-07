#include <iostream>

template <typename T>
struct node{
	node* left;
	node* right;
	T value;
};

template <class T>
class BinaryTree{

private:
	node<T>* root;
	void insert(node<T>* inNode, node<T>* currNode);
	node<T>* search(T key, node<T>* currNode);
	void print(node<T>* n);
	void destroy(node<T>* target);

public:
	BinaryTree();
	BinaryTree(T rootValue);
	~BinaryTree();

	void insert(T key);
	node<T>* search(T key);
	void print();
	void destroy();
	
};

