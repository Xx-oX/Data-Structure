#include<iostream>
using namespace std;

class Node{
public:
	int coef;
	int expo;
	Node *link;
};

int main(){
	Node *front,*curr,*prev;
	for(int i=0;i<5;++i){
		curr = new Node();
		cin>>curr->coef>>curr->expo;
		if(i == 0){
			front = curr;
			curr->link = NULL;
		}
		else{
			prev->link = curr;
		}
		prev = curr;
		curr = curr->link;
	}
	curr = front;
	while(curr != NULL){
		cout<<curr->coef<<"x^"<<curr->expo<<endl;
		curr = curr->link;
	}	
	return 0;
}
