#include<iostream>
using namespace std;

class Stack;

class Node{
	string data;
	Node *next;
	friend class Stack;
public:
	Node():data(""){};
	Node(string str):data(str){};
};

class Stack{
public:
	Stack(string str){
		head = new Node(str);
		head->next = NULL;
		size = 1;
	}

	void Push(string str){
		Node *newNode = new Node(str);
		getTail()->next = newNode;
		newNode->next = NULL;
		size++;
	}

	void Pop(){
		if(isEmpty()){
			cout<<"The stack is empty!!"<<endl;
			return;
		}
		delete getTail();
		getTail()->next = NULL;
		size--;
	}

	string Top(){
		return getTail()->data;
	}

	bool isEmpty(){
		if(size == 0) return true;
		else return false;
	}

	int getSize(){return size;}

	Node* getTail(){
		Node *curr,*prev;
		curr = head;
		while(curr != NULL){
			prev = curr;
			curr = curr->next;
		}
		return prev;
	}

	void print(){
		Node *curr = head;
		while(curr->next != NULL){
			cout<<curr->data<<endl;
			curr = curr->next;
		}
	}

private:
	Node *head;
	int size;
};



int main(){
	Stack S("eins");
	S.Push("zwai");
	S.Push("drei");
	S.Pop();
	S.print();
	return 0;
}
