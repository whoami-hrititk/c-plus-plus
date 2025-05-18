#include <iostream>

struct node{
	int num;
	node* nextNum;
};

int main(){
	node* head = nullptr;
	for(int i = 0; i<5; i++){
		node* new_n = new node;
		new_n->num = i+1;
		new_n->nextNum = head;
		head = new_n;
	}
	node* load_node = head;
	while(load_node){
		std::cout<<load_node->num<<"->";
		load_node = load_node->nextNum;
	}
	std::cout<<"nullptr"<<std::endl;

	while(head){
		node* temp = head;
		head = head->nextNum;
		delete temp;
	}
	return 0;
}