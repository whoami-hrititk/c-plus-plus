#include <iostream>
#include <vector>

struct node {
    int number;
    node* prevNum;
};

int main() {
    std::vector<node*> nodes; // store pointers to dynamically allocated nodes

    node* temp_head = nullptr;

    for (int i = 0; i < 10; i++) {
        node* n = new node;     // dynamically allocate memory
        n->number = i + 1;
        n->prevNum = temp_head; // link to previous node
        temp_head = n;          // move head to new node
        nodes.push_back(n);     // store pointer in vector
    }

    // Print nodes (in reverse order, because we built from tail to head)
    for (auto n : nodes) {
        std::cout << "Node: " << n->number << std::endl;
        if (n->prevNum)
            std::cout << "Previous Node: " << n->prevNum->number << std::endl;
        else
            std::cout << "Previous Node: nullptr" << std::endl;
    }

    // Optional: free memory
    for (auto n : nodes) {
        delete n;
    }

    return 0;
}
