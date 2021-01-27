#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

const int MAX_SIZE = 20;

template <typename T>
class stack {
    public:
        // constructs an empty stack.
        stack() {
            size_ = 0;
        }

        // inserts a new element (val) of type T (T could be integer or string) into the data. 
        // If the data array is full, this function should throw an overflow_error exception with 
        // error message "Called push on full stack.".
        void push(const T &val) {
            if (size_ == MAX_SIZE) {
                throw overflow_error("Called push on full stack.");
            } else {
                data_[size_] = val;
                size_++;
            }
        }

        // removes the last element from data. If the data array is empty, this function should 
        // throw an out_of_range exception with error message "Called pop on empty stack.".
        void pop() {
            if (size_ == 0) {
                throw out_of_range("Called pop on empty stack.");
            } else {
                size_--;
            }
        }

        // returns the top element of stack (last inserted element). If stack is empty, 
        // this function should throw an underflow_error exception with error message 
        // "Called top on empty stack.".
        T top() const {
            if (size_ == 0) {
                throw underflow_error ("Called top on empty stack.");
            } else {
                return data_[size_ - 1];
            }
        }

        // returns true if the stack is empty otherwise it returns false.
        bool empty() const {
            if (size_ == 0) {
                return true;
            } else {
                return false;
            }
        }

    private:
        // An array with maximum size of 20. (Declare a constant in stack.h called MAX_SIZE and set it to 20.)
        T data_[MAX_SIZE];
        
        // stores the current number of elements in the stack.
        int size_;
};

#endif