/*
 * converting infix to postfix
 * unfinished, need to add precedence & 
 * solve the problem when pop out the operators
 * by 0_o @ 2019/11/12 23:49
*/
#include<iostream>
using namespace std;

class Stack;
class Node{
public:
	char data;	
	Node *next;
	Node *prev;
	friend class Stack;
	Node(){};
	Node(char input):data(input){};
};
class Stack{
public:
	Node *front;
	
	Stack(){
		front = NULL;
	}

	void print(){
		Node *curr = front;
		while(curr != NULL){
			cout<<curr->data<<endl;
			curr = curr->next;
		}
	}

	void push(char input){
		Node *newNode = new Node(input);
		if(front == NULL){
			front = newNode;
		}
		else{
			newNode->prev = getBack();
			getBack()->next = newNode;
			newNode->next = NULL;
		}
	}

	char pop(){
		char ret;
		if(getBack() == NULL){
			ret = '0'; 
		}
		else{
			ret = getBack()->data;
			if(getBack() == front){
				front = NULL;
			}
			else{
				getBack()->prev->next = NULL;
				delete(getBack());
			}
		}
		return ret;
	}

	Node* getBack(){
		if(front == NULL){
			cout<<"Stack empty"<<endl;
			return NULL;
		}
		Node *curr = front;
		Node *prev;
		while(curr != NULL){
			prev = curr;
			curr = curr->next;
		}
		return prev;
	}
	
	bool isEmpty(){
		if(front == NULL)
			return true;
		else
			return false;	
	}

};

int main(){
	Stack S;
	char output[100];
	for(int i=0;i<100;++i){
		output[i] = ' ';
	}
	int index = 0;
	while(!cin.eof()){
		char input;
		cin>>input;
		if(input > 64 && input < 91){
			output[index++] = input;
		}
		else{
			if(input == ')'){
				while(!S.isEmpty()){
					char out = S.pop();
					//cout<<endl<<out<<endl;
					output[index++] = out;
				}
			}
			else if(input == '('){
				//donothing
			}
			else{
				S.push(input);
			}
		}
	}
	output[index--] = ' ';
	while(!S.isEmpty()){
		char out = S.pop();
		//cout<<endl<<out<<endl;
		output[index++] = out;
	}

	cout<<endl;
	for(int i=0;i<index;++i)
		cout<<output[i]<<" ";
	cout<<endl;
	return 0;
}
