#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include <cstdlib>
#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
  char data;  // Variable or arithmetic operator 
  char key;  // Used for node name in graphviz 
  TreeNode *left;  // Left child
  TreeNode *right;  // Right child
  TreeNode(char data, char key)
      : data(data), key(key), left(nullptr), right(nullptr) {}
};

class arithmeticExpression {
 public:
  /*
   * Initializes an empty tree and sets the infixExpression_ to the value of
   * parameter passed in.
   */
  arithmeticExpression(const string &expr);

  /*
   * Implementation of destrucor is optional.
   * The destructor should deallocate all the nodes in the tree.
   */
  // ~arithmeticExpression();

  /*
   * Converts the infixExpression_ to its equivalent postfix string and then
   * generates the tree and assigns the root node to the root data field. The
   * key for the first node is 'a', 'b' for the second node and so on.
   */
  void buildTree();

  /* Calls the recursive infix function. */
  void infix();

  /* Calls the recursive prefix function. */
  void prefix();

  /* Calls the recursive postfix function. */
  void postfix();

  /* Calls the recursive visualizeTree function. */
  void visualizeTree(const string &outputFilename);

 private:
  /*
   * Helper function that returns an integer according to the priority of the
   * given operator.
   */
  int priority(char op);

  /*
   * Helper function that returns the postfix notation equivalent to the given
   * infix expression.
   */
  string infix_to_postfix();

  /*
   * Outputs the infix notation of the arithmetic expression tree by performing
   * the inorder traversal of the tree.
   * An opening and closing parenthesis must be added at the beginning and
   * ending of each expression.
   */
  void infix(TreeNode *node);

  /*
   * Outputs the prefix notation of the arithmetic expression tree by performing
   * the preorder traversal of the tree.
   */
  void prefix(TreeNode *node);

  /*
   * Outputs the postfix notation of the arithmetic expression tree by
   * performing the postorder traversal of the tree.
   */
  void postfix(TreeNode *node);

  /*
   * Helper function for Generating the dotty file. This is a recursive
   * function. */
  void visualizeTree(ofstream &outFS, TreeNode *node);

  // void visualizeTree();

  string infixExpression_;
  TreeNode *root_;
};

#endif