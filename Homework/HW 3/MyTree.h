#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

typedef struct BinaryNode {
  std::string myString;
  int myInt;
  BinaryNode *parent;
  BinaryNode *left;
  BinaryNode *right;

  BinaryNode(const std::string &s, int x)
      : myString(s), myInt(x), parent(nullptr), left(nullptr), right(nullptr) {}
} BinaryNode;

class MyTree {
 public:
  MyTree();
  ~MyTree();  // Delete all nodes in the tree

  size_t NumNodes() const { return numNodes_; };

  // Insert new node into first available position (to keep the tree almost
  // complete), return the created node.
  BinaryNode *Insert(const std::string &s, int x);

  string find(int x);

  // Output all strings in pre-order
  // all the strings will be print in one line separated by spaces
  void Preorder() const;

  void preorder(BinaryNode* node) const;

  // Returns a pointer to the node with maximum myInt
  BinaryNode *FindMax() const;

  // Converts the binary tree into a binary search tree (BST) with respect to
  // myInt. That is, move around node values (myString and myInt) to satisfy the
  // BST property.
  void MakeBST();

  // postorder traversal to delete all but root in destructor
  void postorder(BinaryNode* node);

  // void inorder();

  string generate(int x);

 private:
  BinaryNode *root_;
  size_t numNodes_;
};
