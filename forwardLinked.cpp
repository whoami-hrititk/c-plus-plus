#include <iostream>
#include <vector>

struct node{
    int num;
    node* nextNum;
};

int main(){
    std::vector<node*> nodes;
    node* tail = nullptr;
    for(int i = 0; i< 10; i++){
        node* new_n = new node;
        new_n->num = i+1;
        new_n->nextNum = nullptr;

        if(tail != nullptr){
            tail->nextNum = new_n;
        }
        tail = new_n;
        nodes.push_back(new_n);
    }
    for(auto n : nodes){
        std::cout<<"Current Node: "<<n->num<<std::endl;
        
        if(n->nextNum){
            std::cout<<"New Node: "<<n->nextNum->num<<std::endl;
        }else{
            std::cout<<"New Node: "<<"null"<<std::endl;
        }
        delete n;
    }
    return 0;
}