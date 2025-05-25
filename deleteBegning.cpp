#include <iostream>

struct node{
	int num;
	node* nextNum;
};
void printNode(node*& head){
	node* load_node = head;
	while(load_node){
		std::cout<<load_node->num<<" "<<std::endl;
		load_node = load_node->nextNum;
	}
	return;
}

void createNode(node*& head, int value){
	node* new_n = new node;
	new_n->num = value;
	new_n->nextNum = head;
	head = new_n;
	return;
}

void deleteNode(node*& head){
	node* load_node = head;
	head = load_node-> nextNum;
	delete load_node;
	std::cout<<"Latest node deleted!"<<std::endl;
	return;
}

void freeMemory(node*& head){
	
	while(head){
		node* load_node = head;
		head = load_node->nextNum;
		delete load_node;
	}
	std::cout<<"Memory freed!"<<std::endl;
	return;
}

int main(){
	node* head = nullptr;
	for(int i = 1; i<=10; i++){
		createNode(head, i*10);
	}
	printNode(head);
	deleteNode(head);
	printNode(head);
	freeMemory(head);
	return 0;
}