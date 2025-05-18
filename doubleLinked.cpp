#include <iostream>
#include <vector>

struct node{
    int num;
    node* prevNum;
    node* nextNum;
};

int main(){
    std::vector<node*> nodes;
    node* tail = nullptr;
    for(int i = 0; i<10; i++){
        node* new_n = new node;
        new_n->num = i+1;
        new_n->prevNum = nullptr;
        new_n->nextNum = nullptr;
        if(tail){
            tail->nextNum = new_n;
            new_n->prevNum = tail;
        }
        tail = new_n;
        nodes.push_back(new_n);
    }
    for(auto n:nodes){
        std::cout<<"Current Node: "<<n->num<<std::endl;
        if(n->prevNum)
            std::cout<<"Previous Node: "<<n->prevNum->num<<std::endl;
        else
            std::cout<<"Previous Node: "<<"NULL"<<std::endl;
        if(n->nextNum)
            std::cout<<"Next Node: "<<n->nextNum->num<<std::endl;
        else
            std::cout<<"Next Node: "<<"NULL"<<std::endl;

    }
    for(auto n: nodes)
        delete n;
    return 0;
}