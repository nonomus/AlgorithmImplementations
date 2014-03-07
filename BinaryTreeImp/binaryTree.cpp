#include "binaryTree.h"

using namespace std;
//This is an implementation of a binary tree data structure.

template<class T>
BinaryTree<T>::BinaryTree(){
	root = NULL;
}

template<class T>
BinaryTree<T>::BinaryTree(T rootValue){
	node<T>* myRoot = new node<T>;
	myRoot->left = NULL;
	myRoot->right = NULL;
	myRoot->value = rootValue;
	this->root = myRoot;
}

template<class T>
BinaryTree<T>::~BinaryTree(){
	destroy(root);
}

template<class T>
void BinaryTree<T>::insert(T key){
	node<T>* newNode = new node<T>;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = key;
	if(root == NULL){
		root = newNode;
		return;
	}
	insert(newNode, root);
}

template<class T>
void BinaryTree<T>::insert(node<T>* inNode, node<T>* currNode){
	if(inNode->value <= currNode->value){
		if(currNode->left == NULL){
			currNode->left = inNode;
		} else insert(inNode, currNode->left);
	}
	else{
		if(currNode->right == NULL){
			currNode->right = inNode;
		} else insert(inNode, currNode->right);
	}
}

template<class T>
node<T>* BinaryTree<T>::search(T key){
	return search(key, root);
}

template<class T>
node<T>* BinaryTree<T>::search(T key, node<T>* currNode){
	if(currNode == NULL) return NULL;
	else if(key == currNode->value) return currNode;
	else if(key < currNode->value) return search(key, currNode->left);
	else return search(key, currNode->right);
}

template <class T>
void BinaryTree<T>::destroy(){
	destroy(root);
	root = NULL;
}

template <class T>
void BinaryTree<T>::destroy(node<T>* target){
	if(target != NULL){
		destroy(target->left);
		destroy(target->right);
		cout << "DELETING TARGET " << target->value << endl;
		delete target;
	}
}

template <class T>
void BinaryTree<T>::print(){
	print(root);
	cout << endl;
}

template <class T>
void BinaryTree<T>::print(node<T>* n){
	if(n == NULL){
		return;
	}
	cout << n->value << " ";
	print(n->left);
	cout << "  ";
	print(n->right);
}

int main(){
	//char data[4] = {"a", "b", "c", "d"};
	BinaryTree<char> newTree('a');
	newTree.insert('z');
	newTree.insert('d');
	newTree.insert('r');
	newTree.insert('f');
	node<char>* search = newTree.search('d');
	cout << search->value << endl;
	newTree.print();
	return 0;
}