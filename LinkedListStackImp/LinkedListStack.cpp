//This is an implementation of a stack using a linked list.
//Oleksandr Tyberkevych

#include <iostream>

using namespace std;

template <class T> class LinkedListStack{
	struct node{
		node* nextNode;
		T data;
	};

	node stackHead;
	int stackSize;

	public:
	LinkedListStack();

	void push(T data);
	T* pop();
	void printStack();
	void printStackHelper(node* n);
};

//The stack will start out with current node pointing to the stackHead.
template <class T> LinkedListStack<T>::LinkedListStack(){
	stackHead.nextNode = NULL;
}

//Push a piece of data on the nextNode in a linkedList.
//This is done by making a new node, assigning the piece of data to its internal
//data variable, setting nextNode variable of the currNode to the newNode, and
//setting currNode to newNode.
template <class T> void LinkedListStack<T>::push(T data){
	node* newNode = new node;
	newNode->data = data;
	newNode->nextNode = stackHead.nextNode;
	stackHead.nextNode = newNode;
}

//Check whether the stack is empty, and, if its not, pop a piece of data.
//PRECONDITION: List is not empty. This will return a null pointer if its empty.
template <class T> T* LinkedListStack<T>::pop(){
	if(stackHead.nextNode == NULL){
		cout << "The list is empty. Cannot pop data. Returning null.\n";
		return NULL;
	}

	T* data = &stackHead.nextNode->data;
	node* nextStackNode = stackHead.nextNode->nextNode;
	delete stackHead.nextNode;
	stackHead.nextNode = nextStackNode;
	return data;
}

//Print the stack from top to bottom.
template <class T> void LinkedListStack<T>::printStack(){
	cout << "Stack Top:" << endl;
	printStackHelper(stackHead.nextNode);
	cout << "Stack Bottom." << endl;
}
//A recursive helper function that goes through each available node and prints
//its value.
template <class T> void LinkedListStack<T>::printStackHelper(node* n){
	cout << n->data << endl;
	if(n->nextNode != NULL){
		printStackHelper(n->nextNode);
	}
}

int main(){
	LinkedListStack<int> stack1;
	stack1.push(5);
	stack1.push(7);
	stack1.push(12);
	stack1.printStack();
	cout << *stack1.pop() << endl;
	cout << *stack1.pop() << endl;
	cout << *stack1.pop() << endl;
	return 0;
}