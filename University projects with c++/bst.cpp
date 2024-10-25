#include <cstdio>
#include <fstream>
#include <string>  // aka MyString
#include <vector>  // aka ResizableArray
using namespace std;

template <class T>
struct BSTNode {  // struct = class, nur per default alles public
  BSTNode(T const& x) : left_{nullptr}, cont_{x}, right_{nullptr} {}

  ~BSTNode() {
    if (left_ != nullptr) delete left_;
    if (right_) delete right_;
  }

  BSTNode* left_;
  T cont_;
  BSTNode* right_;
};

template <class T>
class BST {
  BSTNode<T>* root_;  // the root_ of the tree
  int size_;          // stores number of items
 public:
  BST() : root_{nullptr}, size_{0} {}

  ~BST() { delete root_; }

  int size() const { return size_; }

  // return height of the tree:
  int get_height() { return get_height(root_); }

  // suche x im Baum:
  bool find(T x) { return find(x, root_); }

  // eigentlich inorder:
  vector<T> get_sorted() {
    vector<T> result;
    result.reserve(size_);
    inorder(root_, result);
    return result;
  }

  vector<T> preorder() {
    vector<T> result;
    result.reserve(size_);
    preorder(root_, result);
    return result;
  }

  // insert new element x into this tree as a new leaf
  void insert(T const& x) {
    root_ = insert(x, root_);
    ++size_;
  }

  int get_depth(T const& x) const { return get_depth(x, root_); }

 private:
  void inorder(BSTNode<T>* node, vector<T>& v) {
    if (node == nullptr) return;
    inorder(node->left_, v);
    v.push_back(node->cont_);
    inorder(node->right_, v);
  }

  void preorder(BSTNode<T>* node, vector<T>& v) {
    if (node == nullptr) return;
    v.push_back(node->cont_);
    preorder(node->left_, v);
    preorder(node->right_, v);
  }

  int get_height(BSTNode<T>* node) {
    if (node == nullptr) return 0;  // leerer (Teil)baum

    int linke_TB_Hoehe = get_height(node->left_);
    int rechte_TB_Hoehe = get_height(node->right_);

    // gib Maximum der beiden Teilbaumenhoehen (+1) zurueck:
    return (linke_TB_Hoehe > rechte_TB_Hoehe ? linke_TB_Hoehe
                                             : rechte_TB_Hoehe) +
           1;
  }

  bool find(T x, BSTNode<T>* current) {
    if (current == nullptr) return false;
    if (current->cont_ == x) return true;
    if (x < current->cont_)
      return find(x, current->left_);
    else
      return find(x, current->right_);
  }

  // recursive insert into BST; return ptr to either new node or current
  BSTNode<T>* insert(T const& x, BSTNode<T>* current) {
    if (current == nullptr) {
      // base case: create node and return pointer to it
      return new BSTNode<T>(x);
    }

    // recursive case: compare x with current->cont and go left/right
    if (x < current->cont_)
      current->left_ = insert(x, current->left_);
    else
      current->right_ = insert(x, current->right_);
    return current;  // return pointer to passed pointer
  }

  int get_depth(T const& x, BSTNode<T>* current) const {
    if (current == nullptr) {
      return -1; 
    }
    if (x == current->cont_){
      return 0;
    } 
    else{
      if (x < current->cont_){
        int lTB = get_depth(x, current->left_);
        if (lTB != -1) {
          return lTB + 1; 
        }
      }
      else{
        int rTB = get_depth(x, current->right_);
        if (rTB != -1) {
          return rTB + 1; 
        }
      }
    }
    return -1;
  }
};

void print_depth(BST<string> const& MyTree, char const search_value[]) {
  printf("Depth of ");
  printf(search_value);
  printf(" is %i\n", MyTree.get_depth(search_value));
}

int main() {
  BST<string> MyTree;

  MyTree.insert("Grace");
  MyTree.insert("Bob");
  MyTree.insert("Erin");
  MyTree.insert("Alice");
  MyTree.insert("Judy");
  MyTree.insert("David");
  MyTree.insert("Heidi");
  MyTree.insert("Carol");
  MyTree.insert("Frank");
  MyTree.insert("Ivan");
  MyTree.insert("Malory");

  print_depth(MyTree, "David");
  print_depth(MyTree, "Carol");
  print_depth(MyTree, "Olivia");

  return 0;
}
