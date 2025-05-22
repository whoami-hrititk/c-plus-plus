#include <iostream>

struct node{
	int num;
	node* nextNum;
};

void printNode(node*& head){
	node* load_node = head;
	int count = 0;
	while(load_node){	
		std::cout<<"Node "<<++count<<" :"<<load_node->num<<std::endl;
		load_node = load_node->nextNum;
	}
	return;
}

void insertNode(node*& head, int value){
	node* new_n = new node;
	new_n->num = value;
	new_n->nextNum = nullptr;
	if(head){
		node* save_n = head;
		save_n = head;
		while(save_n){
			save_n = head->nextNum;
		}
		save_n = new_n;
		head->nextNum = save_n;
	}else{
		head = new_n;
	}

	printNode(head);
	return;
}

int main(){
	node* head = nullptr;
	int num;
	while(true){
		std::cout<<"Enter a value to add in new node: ";
		std::cin>>num;
		insertNode(head, num);
	}
	return 0;
}
