#include <iostream>

struct node{
	int num;
	node* nextNum;
};

void printNode(node*& head){
	node* load_node = head;
	int count = 0;
	while(load_node){
		std::cout<<"Node "<< ++count <<": "<<load_node->num<<std::endl;
		load_node = load_node->nextNum;
	}
	return;
}

void insertNode(node*& head, int value){
	node* new_n = new node;
	new_n->num = value;
	new_n->nextNum = head;
	head = new_n;
	printNode(head);
	return;
}

void deleteNode(node*& head){
	while(head){
		node* temp = head;
		head = head->nextNum;
		delete temp;
	}
	return;
}


int main(){
	node* head = nullptr;
	int num;
	while(true){
		std::cout<<"Enter the value to insert in node: ";
		std::cin>>num;
		insertNode(head, num);
	}
	deleteNode(head);
	return 0;
}