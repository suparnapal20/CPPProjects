/*
  TreeNode.h is the header file that declares the value variable, the id variable,
  the left variable, the right variable, and the function names
*/
template <typename E>

class TreeNode {
public:
  E value;          // data value
  int id;           // id for comparison
  TreeNode* left;   // left child tree node
  TreeNode* right;  // right child tree node

  /*
    Constructor initializes id and value variables and left and right pointers
  */
  TreeNode() {
    id = 0;
    value = E();
    left = nullptr;
    right = nullptr;
  }

  /*
    Overloaded constructor initializes left and right pointers and sets values of
    id and element
    @param v: data value to be added to node, i: key to be added to node
  */
  TreeNode(E v, int i) {
    value = v;
    id = i;
    left = nullptr;
    right = nullptr;
  }

  /*
    Destructor for TreeNode
  */
  virtual ~TreeNode() {}
};
