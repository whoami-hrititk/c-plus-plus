#include <iostream>

struct node{
	int num;
	node* nextNum;
};

void printNode(node* head){
	if(!head){
		std::cout<<"No Node!"<<std::endl;
		return;
	}
	node* load_n = head;
	while(load_n){
		std::cout<<load_n->num<<std::endl;
		load_n = load_n->nextNum;
	}
	return;
}

void deleteNode(node*& head){
	if(!head->nextNum){
		delete head;
		head = nullptr;
	}
		
	if(!head){
		return;
	}
	node* load_node = head;
	while(load_node->nextNum){
		if(load_node->nextNum->nextNum == nullptr){
			node* last_n = load_node;
			load_node = load_node->nextNum;
			last_n->nextNum = nullptr;
			delete load_node;
			break;
		}
		load_node = load_node->nextNum;
	}
	std::cout<<"Last Node is removed!"<<std::endl;
	return;

}

void createNode(node*& head, int value){
	node* new_n = new node;
	new_n->num = value;
	new_n->nextNum = nullptr;

	if(head){
		node* load_n = head;
		while(load_n->nextNum){
			load_n = load_n->nextNum;
		}
		load_n->nextNum = new_n;
	}else{
		head = new_n;
	}
	return;
}

void freeMemory(node* head){
	while(head){
		node* load_n = head;
		head = load_n->nextNum;
		delete load_n;
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