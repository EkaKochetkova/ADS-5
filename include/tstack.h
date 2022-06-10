// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T arr[1000];
    int top;
    
public:
    TStack() : top(-1) {
    }
    
    bool isEmpty() {
        return top == -1; 
    }
    
    bool isFull() {
        return top == size - 1; 
    }
    
    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }
    
    T get() const {
        if (!isEmpty()) {
            return arr[top];
        }    
    }
    
    void push(T value) {
        if (!isFull()) {
            arr[top++] = value;
        }       
    }
    
};
#endif  // INCLUDE_TSTACK_H_
