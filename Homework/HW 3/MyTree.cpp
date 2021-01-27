#include <iostream>
#include <string>
#include <cstdio>

#include "MyTree.h"

using namespace std;

MyTree::MyTree() : root_(nullptr), numNodes_(0) {
  // Initialize the tree without a root (empty tree)
}

MyTree::~MyTree() {
  // Delete all nodes except the root
  postorder(root_);

  if (root_) {
    // Delete the root
    delete root_;
  }
}

// Insert new node into first available position (to keep the tree almost
// complete), return the created node.
BinaryNode *MyTree::Insert(const std::string &s, int x) {
  BinaryNode *node = new BinaryNode(s, x);

  /* if (root_ == nullptr) {
    root_ = node;
  } else {

  }
  // Insert the node
  return node; */
    string var = find(numNodes_+1);
    BinaryNode *n = root_;

    if(n == nullptr) { 
      root_ = node; 
      numNodes_++; 
      return node; 
    }

    cout << var << endl;
    
    int i = 0;;
    for(i = 1; i < (int)(var.length()-1); i ++){
        if(var[i] == '0') { 
          n = n->left; 
        }
        
        if(var[i] == '1') { 
          n = n->right; 
        }
    }

    if(var[i] == '0') { 
      n->left = node; 
    }
    
    if(var[i] == '1') { 
      n->right = node; 
    }

    numNodes_++;

  return node;
}

string MyTree::find(int x){
    string temp;
    string temp2;
    
    while (x != 0) {
      temp = temp2;
      temp = (x%2 == 0 ? '0':'1');
      temp = temp + temp2;
  
      x /= 2;
    }

    return temp;
}

void MyTree::preorder(BinaryNode* node) const {
  if (node == nullptr) {
    return;
  }

  cout << node->myInt;
  preorder(node->left);
  preorder(node->right);
}

// Output all strings in pre-order
// all the strings will be print in one line separated by spaces
void MyTree::Preorder() const {
  preorder(root_);
  cout << " ";
}


// Returns a pointer to the node with maximum myInt
BinaryNode *MyTree::FindMax() const {
  BinaryNode* max = root_;

  if (numNodes_ > 2) {
    while (max->right != nullptr) {
      max = max->right;
    }
  }
  return max;
}

// Converts the binary tree into a binary search tree (BST) with respect to
// myInt. That is, move around node values (myString and myInt) to satisfy the
// BST property.
void MyTree::MakeBST() {
  if (numNodes_ > 0) {
    int num = 0;
    BinaryNode** arr = new BinaryNode* [numNodes_];
    int* intarr = new int[numNodes_];

    
  }
}

// postorder traversal to delete all but root in destructor
void MyTree::postorder(BinaryNode* node){
  if (node == nullptr){
    return;
  }

  postorder(node->left);
  postorder(node->right);
  delete node;
}


string generate(int x) {
    const int MAX = 62;
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                           'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string temp = ""; 
    
    for (int i = 0; i < x; i++) {
        temp = temp + alphabet[rand() % MAX]; 
    }
      
    return temp; 
}