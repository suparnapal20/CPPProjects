/*
  Tree.h is the header file that declares the root variable, the size variable,
  and the function names
*/
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename E>

class Tree {
public:
  TreeNode<E>* root;
  int size;
  Tree();
  ~Tree();
  TreeNode<E>* getRoot();
  E search(int id);
  bool contains(int id);
  void insert(TreeNode<E>* node);
  void remove(int id);
  TreeNode<E>* getSuccessor(TreeNode<E>* d);
  void inOrder(TreeNode<E>* node);
  void inOrderFile(TreeNode<E>* node, string fileName);
};

/*
  Constructor for Tree.
*/
template <typename E>
Tree<E>::Tree() {
  root = nullptr;
  size = 0;
}

/*
  Destructor for Tree.
*/
template <typename E>
Tree<E>::~Tree() {
  return;
}

/*
  getRoot
  returns root of the tree
  @return root: root of tree.
*/
template <typename E>
TreeNode<E>* Tree<E>::getRoot(){
  return root;
}

/*
  search
  Searches for a node in tree given the id.
  @param id: id to find.
  @return E: node to return.
*/
template <typename E>
E Tree<E>::search(int id) {
  if (root == nullptr) {
    return E();
  }

  TreeNode<E>* curr = root;
  while (curr->id != id) {
    if (id < curr->id) {
      curr = curr->left;
    }

    else {
      curr = curr->right;
    }

    if (curr == nullptr) {
      return E();
    }
  }
  return curr->value;
}

/*
  contains
  Checks if tree contains node with id k.
  @param id: id to find
  @return true or false
*/
template <typename E>
bool Tree<E>::contains(int id) {
  if (root == nullptr) {
    return false;
  }

  TreeNode<E>* curr = root;
  while (curr->id != id) {
    if (id < curr->id) {
      curr = curr->left;
    }

    else {
      curr = curr->right;
    }

    if (curr == nullptr) {
      return false;
    }
  }
  return true;
}

/*
  insert
  Inserts node in tree.
  @param node: tree node to insert.
*/

template <typename E>
void Tree<E>::insert(TreeNode<E>* node) {
  if (root == nullptr) {
    root = node;
  }
  else {
    TreeNode<E>* curr = root;
    TreeNode<E>* parent;

    while (true) {
      parent = curr;
      if (node->id < curr->id) {
        curr = curr->left;
        if (curr == nullptr) {
          parent->left = node;
          break;
        }
      }
      else {
        curr = curr->right;
        if (curr == nullptr) {
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}

/*
  remove
  Remove a node from tree.
  @param id: id to find and delete.
*/
template <typename E>
void Tree<E>::remove(int id) {
  if (root == nullptr) {
    return;
  }
  TreeNode<E>* curr = root;
  TreeNode<E>* parent = root;
  bool isLeft = true;

  while (curr->id != id) {
    parent = curr;
    if (id < curr->id) {
      curr = curr->left;
      isLeft = true;
    }
    else {
      curr = curr->right;
      isLeft = false;
    }
    if (curr == nullptr) {
      return;
    }
  }

  // case 1: node has no children
  if ((curr->left == nullptr) && (curr->right == nullptr)) {
    if (curr == root) {
      root = nullptr;
    }
    else if (isLeft) {
      parent->left = nullptr;
    }
    else {
      parent->right = nullptr;
    }
  }

  // case 2: node has one child on the left
  else if (curr->right == nullptr) {
    if (curr == root) {
      root = curr->left;
    }
    else if (isLeft) {
      parent->left = curr->left;
    }
    else {
      parent->right = curr->left;
    }
  }

  // case 3: node has one child on the right
  else if (curr->left == nullptr) {
    if (curr == root) {
      root = curr->right;
    }
    else if (isLeft) {
      parent->left = curr->right;
    }
    else {
      parent->right = curr->right;
    }
  }

  // case 4: node has two children
  else {
    TreeNode<E>* successor = getSuccessor(curr);

    if (curr == root) {
      root = successor;
    }
    else if (isLeft) {
      parent->left = successor;
    }
    else {
      parent->right = successor;
    }

    successor->left = curr->left;
  }
  size--;
  delete curr;
}

/*
  getSuccessor
  Find a node's left most child of its right child
  @param d: node to find successor for.
  @return successor node.
*/
template <typename E>
TreeNode<E>* Tree<E>::getSuccessor(TreeNode<E>* d) {
  TreeNode<E>* sp = d;
  TreeNode<E>* successor = d;
  TreeNode<E>* curr = d->right;

  while (curr != nullptr) {
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if (successor != d->right) {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}

/*
  inOrder
  Inorder traversal printed to terminal starting at some node.
  @param node: node to begin traversal
*/
template <typename E>
void Tree<E>::inOrder(TreeNode<E>* node) {
  if (node == nullptr) {
    return;
  }

  inOrder(node->left);
  std::cout << "ID: " << node->id << endl;
  node->value.print();
  std::cout << endl;
  inOrder(node->right);
}

/*
  inOrderFile
  Inorder traversal written in file starting at some node.
  @param node: node to begin traversal
*/
template <typename E>
void Tree<E>::inOrderFile(TreeNode<E>* node, string fileName) {
  if (node == nullptr) {
    return;
  }

  inOrderFile(node->left, fileName);
  node->value.printFile(node->id, fileName);
  inOrderFile(node->right, fileName);
}
