#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct Node {
  string data;
  unsigned int count;  // Increment if the same data is inserted.
  Node* left;
  Node* right;
  unsigned int height;

  Node(const string &data)
      : data(data), count(1), left(nullptr), right(nullptr) {}
} Node;

class AVLTree {
    public:
        // int height;
        void insert(const string& str);
        int balanceFactor(Node* node) const;
        void printBalanceFactors() const;
        void visualizeTree(const string& outputFilename) const;
        int heights(Node* node);
    private:
        Node *findUnbalancedNode(Node* node, const string& str) const;
        void rotate(Node* node, const string& str);
        Node *rotateLeft(Node* node);
        Node *rotateRight(Node* node);
        void printBalanceFactors(Node* node) const;
        void visualizeTree(ofstream& outFS, Node* node) const;
        int max(int a, int b) const;  
        // int heights(Node* node) const;

        Node *root_;
};


#endif