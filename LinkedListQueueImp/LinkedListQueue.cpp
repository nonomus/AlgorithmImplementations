//Oleksandr Tyberkevych
//This is an implementation of a linked list queue.
#include <iostream>

using namespace std;

template <class T> class LinkedListQueue{
    struct node{
        node* nextNode;
        T data;
    };
    node head, tail;
    int qSize;

    public:
    LinkedListQueue();
    void enqueue(T data);
    T front();
    void dequeue();
    void printQueue();
    void printQueueHelper(node *n);
};

//Initialize the nextNodes as NULL.
template <class T> LinkedListQueue<T>::LinkedListQueue(){
    head.nextNode = NULL;
    tail.nextNode = NULL;
}

//Add an element to the back of the queue.
template <class T> void LinkedListQueue<T>::enqueue(T data){
    node *n = new node;
    n->nextNode = NULL;
    n->data = data;

    if(head.nextNode == NULL){
        head.nextNode = n;
    }
    if(tail.nextNode == NULL){
        tail.nextNode = n;
    }else{
        tail.nextNode->nextNode = n;
        tail.nextNode = n;
    }
}

//Try to remove an element from the front of the queue.
template <class T> void LinkedListQueue<T>::dequeue(){
    if(head.nextNode == NULL){
        cout << "No elements in the queue. Can't dequeue.\n";
        return;
    }
    node* tempNode = head.nextNode->nextNode;
    if(tail.nextNode == head.nextNode) tail.nextNode = tempNode;
    delete head.nextNode;
    head.nextNode = tempNode;
}

//Prints the queue from front to back.
template <class T> void LinkedListQueue<T>::printQueue(){
    if(head.nextNode != NULL) printQueueHelper(head.nextNode);
}

//Helper recursive function to printQueue.
template <class T> void LinkedListQueue<T>::printQueueHelper(node *n){
    cout << n->data << endl;
    if(n->nextNode != NULL) printQueueHelper(n->nextNode);
}

//Returns the data held in the front of the queue. Has undefined behavior
//when the queue is empty.
template <class T> T LinkedListQueue<T>::front(){
    return head.nextNode->data;
}

int main(){

    LinkedListQueue<int> q;
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(20);
    q.enqueue(5);
    cout << q.front() << endl;
    q.printQueue();
    return 0;

}
