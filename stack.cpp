// OPTION 2 - IMPLEMENT STACK
// DO NOT SHARE

#include <cstdint>
#include <cstdlib>
#include <vector>

using namespace std;

// 2. Implement a growable integer stack (without using container libraries like vector, list, etc.) 
//    that satisfies the following requirements:

// `push` adds a given value to the top
// `pop`  returns and removes the value at the top
// `peek` returns the value at the top
// `size` returns the count of values

class IntStack {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
    };
    Node* topNode;
    int count;

public:
    IntStack() : topNode(nullptr), count(0) {}

    void push(int value) {
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
        count++;
    }

    int pop() {
        if (topNode == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        int value = topNode->value;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
        return value;
    }

    int peek() {
        if (topNode == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->value;
    }

    int size() const {
        return count;
    }
};
