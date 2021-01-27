#include <iostream>
#include <string>
#include <fstream>
#include "AVLTree.h"

using namespace std;

// Insert an item to the binary search tree and perform rotation if necessary.
void AVLTree::insert(const string& str) {
    Node* node = root_;
    if( root_ == nullptr){
        root_ = new Node(str);
    }
    else{
        while(node != nullptr){
            if(node->data > str){
                if(node->left == nullptr){
                    node->left = new Node(str);
                    node->left->parent = node;
                    if(node->parent == root_){
                        rotate(root_);
                        return;
                    }
                    Node* nB = findUnbalancedNode(node);
                    if (nB){
                        rotate(nB);
                    }
                    return;
                }
                else{
                    node = node->left;
                }
            }

            else if(node->data < str){
                if(node->right == nullptr){
                    node->right = new Node(str);
                    node->right->parent = node;
                    if(node->parent == root_){
                        rotate(root_);
                        return;
                    }
                    Node* nB = findUnbalancedNode(node);
                    if (nB){
                        rotate(nB);
                    }
                    return;
                }
                else{
                    node = node->right;
                }

            }
            else{
                return;
            }
        }
    }
}

// Return the balance factor of a given node.
int AVLTree::balanceFactor(Node* node) const {
    int leftHeight = -1;
    if (node->left)
    {
        leftHeight = node->left->height;
    }

    int rightHeight = -1;
    if (node->right)
    {
        rightHeight = node->right->height;
    }

    return leftHeight - rightHeight;
}

// Traverse and print the tree in inorder notation. Print the string followed by 
// its balance factor in parentheses followed by a , and one space.
void AVLTree::printBalanceFactors() const {
    return printBalanceFactors(); 
}

// Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
void AVLTree::visualizeTree(const string& outputFilename) const {
    ofstream outFS(outputFilename.c_str());
    if (!outFS.is_open()) {
        cout << "Error" << endl;
        return;
    }
    outFS << "digraph G {" << endl;
    visualizeTree(outFS, root_);
    outFS << "}";
    outFS.close();
    string jpgFilename =
      outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
     system(command.c_str());
}

//////////////////////////////////////////////////////////////////////////////////////////////

// Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
Node AVLTree::*findUnbalancedNode(Node* node, const string& str) {
    Node* curr = node;


}

// Implement four possible imbalance cases and update the parent of the given node.
void rotate(Node* node, const string& str) {

}

// Rotate the subtree to left at the given node and returns the new subroot.
Node AVLTree::*rotateLeft(Node* node) {
    Node *y = node->right;  
    Node *temp = y->left;  
  
    // Perform rotation  
    y->left = node;  
    node->right = temp;  
  
    // Update heights  
    node->height = max(heights(node->left),     
                    heights(node->right)) + 1;  
    y->height = max(heights(y->left),  
                    heights(y->right)) + 1;  
  
    // Return new root  
    return y;  
}

// Rotate the subtree to right at the given node and returns the new subroot.
Node AVLTree::*rotateRight(Node* node) {
    Node *x = node->left;  
    Node *temp = x->right;  
  
    // Perform rotation  
    x->right = node;  
    node->left = temp;  
  
    // Update heights  
    node->height = max(heights(node->left), 
                       heights(node->right)) + 1;  
    x->height = max(heights(x->left), 
                    heights(x->right)) + 1;  
  
    // Return new root  
    return x;  
}

void printBalanceFactors(Node* node) {
    if (node == nullptr) { 
        return;  
    }

    return heights(node->left) - heights(node->right); 
}

void visualizeTree(ofstream& outFS, Node* node) {
    if (node) {
    if (node->left) {
      visualizeTree(outFS, node->left);
      outFS << node->data << " -> " << node->left->data << ";" << endl;
    }
    if (node->right) {
      visualizeTree(outFS, node->right);
      outFS << node->data << " -> " << node->right->data << ";" << endl;
    }
  }
}

int heights(Node *node) {  
    if (node == nullptr) {  
        return 0;  
    }

    return node->height;  
}  

int max(int a, int b) {  
    return (a > b)? a : b;  
}  