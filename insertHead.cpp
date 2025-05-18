#include <iostream>

struct node{
	int num;
	node* nextNum;
};

int main(){
	node* head = nullptr;
	for(int i = 5; i<=25; i+=5){
		node* new_n = new node;
		new_n->num = i;
		new_n->nextNum = head;
		head = new_n;
	}
	node* load_n = head;
	while(load_n){
		if(load_n->nextNum)
			std::cout<<"Current: "<<load_n->num<<" Next: "<<load_n->nextNum->num<<std::endl;
		else
			std::cout<<"Current: "<<load_n->num<<" Next: NULL"<<std::endl;
		load_n = load_n->nextNum;
	}
	return 0;
}