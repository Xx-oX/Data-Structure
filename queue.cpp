#include<iostream>
using namespace std;

class Queue;

class Node{
	string data;
	Node *next;
	friend class Queue;
public:
	Node():data(""){};
	Node(string str):data(str){};
};

class Queue{
public:
	Queue(string str){
		head = new Node(str);
		head->next = NULL;
		size = 1;
	}

	void Push(string str){
		Node *newNode = new Node(str);
		getTail()->next = newNode;
		size++;
	}

	void Pop(){
		if(isEmpty()){
			cout<<"The queue is empty!!"<<endl;
			return;
		}
		Node *delNode = head;
		head = head->next;
		delete(delNode);
		size--;
	}
	
	string getFront(){return head->data;}
	
	string getBack(){return getTail()->data;}
	
	Node* getHead(){return head;}

	Node* getTail(){
		Node *curr = head;
		Node *prev;
		while(curr != NULL){
			prev = curr;
			curr = curr->next;
		}
		return prev;
	}

	bool isEmpty(){
		if(size == 0) return true;
		else return false;
	}

	int getSize(){return size;}
	
	void print(){
		Node *curr = getHead();
		for(int i=0;i<getSize();++i){
			cout<<curr->data<<endl;
			curr = curr->next;
		}
		cout<<endl;
	}
private:
	Node *head;
	int size;
};


int main(){
	Queue Q("eins");
	Q.Push("zwai");
	Q.Push("drei");
	Q.Pop();
	Q.print();
	return 0;
}
