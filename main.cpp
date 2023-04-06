#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next = NULL;
};

struct arrayLinkedList {
    struct Node* head = NULL;
    int top = -1;
};

bool isEmpty(struct arrayLinkedList &stack_) {
    if (stack_.top == -1) {
        return true;
    }
    return false;
}

bool isFull(struct arrayLinkedList &stack_) {
    // Linked list implementation of a stack is never full
    return false;
}

void push(struct arrayLinkedList &stack_, int element) {
    struct Node* node = new Node;
    node->data = element;

    if(isEmpty(stack_)) {
        stack_.head = node;
    }
    else {
        node->next = stack_.head;
        stack_.head = node;
    }
    stack_.top++;
}

void pop(struct arrayLinkedList &stack_) {
    if (isEmpty(stack_)) {
        cout << "stack Underflow!\n";
        return;
    }

    struct Node* temp = stack_.head;
    stack_.head = stack_.head->next;
    delete temp;
    stack_.top--;
}

void stackTop(struct arrayLinkedList &stack_) {
    if (isEmpty(stack_)) {
        return;
    }
    cout << stack_.head->data<<"\n";
}

void display(struct arrayLinkedList &stack_) {
    if (isEmpty(stack_)) {
        return;
    }
    struct Node* current = stack_.head;
    cout << "[ ";
    while ((*current).next != NULL) {
        cout << current->data << " ,";
        current = current->next;
    }
    cout <<current->data<< "]\n";
}

int main() {
    // Example usage
    arrayLinkedList my_stack;
    my_stack.top = -1;

    push(my_stack, 8);
    push(my_stack, 10);
    push(my_stack, 5);
    push(my_stack, 11);
    push(my_stack, 15);
    push(my_stack, 23);
    push(my_stack, 6);
    push(my_stack, 18);
    push(my_stack, 20);
    push(my_stack, 17);
    display(my_stack);
    pop(my_stack);
    pop(my_stack);
    pop(my_stack);
    pop(my_stack);
    pop(my_stack);
    display(my_stack);
    push(my_stack, 4);
    push(my_stack, 30);
    push(my_stack, 3);
    push(my_stack, 1);
    display(my_stack);
}
