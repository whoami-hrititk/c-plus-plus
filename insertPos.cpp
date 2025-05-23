#include <iostream>

struct node{
	int num;
	node* nextNum;
};

void printNode(node*& head){
	int count= 0;
	node* load_node = head;
	while(load_node){
		std::cout<<"Node "<<++count<<" : "<<load_node->num<<std::endl;
		load_node = load_node->nextNum;
	}
	std::cout<<"Node "<<++count<<" : NULL"<<std::endl;
	return;
}

void createNode(node*& head, int value){
	node* new_n = new node;
	new_n->num = value;
	new_n->nextNum = nullptr;

	if(head){
		node* load_node = head;
		while(load_node->nextNum){
			load_node = load_node->nextNum;
		}
		load_node->nextNum = new_n;
	}else{
		head = new_n;
	}
	return;
}

void insertNode(node*& head,int value,int pos){
	node* new_n = new node;
	new_n->num = value;
	new_n->nextNum = nullptr;
	if(pos == 1){
		new_n->nextNum = head;
		head = new_n;
		return;
	}
	if(pos <= 0){
    std::cout << "Position must be greater than 0.\n";
    return;
	}

	node* load_node = head;
	for(int i = 1; i<pos-1 && load_node != nullptr; ++i){
		load_node = load_node->nextNum;
	}
	if(!load_node){
		std::cout<<"Invalid Position!"<<std::endl;
		return;
	}
	new_n->nextNum = load_node->nextNum;
	load_node->nextNum = new_n;
	
	return;
}

void freeMemory(node*& head){
	while(head){
		node* load_node = head;
		head = load_node->nextNum;
		delete load_node;
	}
	std::cout<<"Memory was freed!"<<std::endl;
	return;
}

int main(){
	node* head = nullptr;

	for(int i = 0; i<10 ; i++){
		createNode(head, i*10);
	}
	printNode(head);
	int value, pos;
	std::cout<<"Enter the value to insert: ";
	std::cin>>value;
	std::cout<<"Enter the position to insert the value: ";
	std::cin>>pos;
	insertNode(head, value, pos);
	printNode(head);
	freeMemory(head);
	return 0;
}