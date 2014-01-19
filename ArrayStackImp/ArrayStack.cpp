//This is an implementation of a stack data structure using an array.
//Oleksandr Tyberkevych
#include <iostream>

using namespace std;

template <class T> class ArrayStack{
	private:
	int stackTop, stackSize;
	T* stack;

	public:
	ArrayStack(int arrSize);
	~ArrayStack();
	void printStack();
	void push(T data);
	T* pop();
};

//Initialize the top of the stack to be position -1 in the array (meaning no 
//data) and create the constant size of the stack array based on arrSize.
template<class T> ArrayStack<T>::ArrayStack(int arrSize){
	stackTop = -1;
	stackSize = arrSize;
	stack = new T[arrSize];
}

//Clears memory allocated for the stack.
template<class T> ArrayStack<T>::~ArrayStack(){
	delete[] stack;
}

//Checks if the stack is full, and if its not, pushes a piece of data onto it.
template<class T> void ArrayStack<T>::push(T data){
	if(stackTop + 1 >= stackSize){
		cout << "Size limit reached. Cannot push more data on the stack.\n";
		return;
	}
	stackTop++;
	stack[stackTop] = data;
}

//Checks if the stack has any items on it, and, if it does, pops the last item.
template <class T> T* ArrayStack<T>::pop(){
	if(stackTop < 0){
		cout << "The stack is empty. Cannot pop data off of an empty stack.\n";
		return NULL;
	}
	return &stack[stackTop--];
}

//Prints the stack in LIFO order.
template<class T> void ArrayStack<T>::printStack(){
	cout << "Stack Start:\n";
	for(int i = stackTop; i >= 0; i--){
		cout << stack[i] << endl;
	}
	cout << "Stack End.\n";
}

int main(){
	cout << "This is a sample output." << endl;
	ArrayStack<int> stack1(5);

	for(int i = 0; i < 6; i++){
		stack1.push(i);
	}
	stack1.printStack();

	for(int i = 0; i < 6; i++){
		stack1.pop();
	}
	stack1.printStack();

	for(int i = 0; i < 3; i++){
		stack1.push(i);
	}
	stack1.printStack();
	return 0;
}