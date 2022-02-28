#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct Node {
  int data; // value held in node
  Node *left; // ptr to left node
  Node *right; // ptr to right node
};

/****
* PSEUDOCODE:
*  Goals:
*  - Helper function that inserts node into tree
*  Algorithm:
*    Create ptr to new node
*    Assign the data to the node
*    Assign NULL to the left and right ptr since they are the lowest level 
*    of the tree
*    return ptr to the node
*/

Node* NewNode(int data) {
  Node* node = new Node; // ptr to new node in the tree
  node->data = data;
  node->left = node->right = NULL;
  return (node);
}

/****
* PSEUDOCODE:
*  Goals:
*  - Create a tree from level order input
*  Algorithm:
*    if(index is less than digits in the tree)
*      Create node that serves as the root of a subtree
*      Insert its left child recursively (left child is at 2*i+1 index)
*      Insert its right child recursively (right child is at 2*i+2 index)
*    return root
*/

Node* InsertLevelOrder(std::vector<int> vec, Node* root, int i, int n) {
  if(i < n) {
    Node* temp = NewNode(vec[i]); // current root node
    root = temp;

    //insert left child
    root->left = InsertLevelOrder(vec, root->left, 2*i+1, n);

    //insert right child
    root->right = InsertLevelOrder(vec, root->right, 2*i+2,n);
  }
  return root;
}

/****
* PSEUDOCODE:
*  Goals:
*  - Traverse a tree and put its values inorder
*  Algorithm:
*    if(root isn't NULL)
*      Traverse to leftmost node recursively
*      Insert value into list
*      Traverse to rightmsot node recursively
*/

void InOrder(Node* root, std::vector<int> vec, std::vector<int> &vec2) {
  if(root != NULL) {
    InOrder(root->left, vec, vec2);
    vec2.push_back(root->data);
    InOrder(root->right, vec, vec2);
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - Determine if values are in numerical order
*  Algorithm:
*    Create bool BST that signifies if a tree is a BST, initialized to true
*    for list of numbers up to size-1
*      if previous number is higher than next number
*        Not a binary search tree
*    return BST
*/

bool IsBST(std::vector<int> vec) {
  bool BST = true; // signifies if a tree is a binary search tree

  for(int i=0; i<(vec.size()-1); i++) {
    if(vec[i] > vec[i+1]) {
      BST = false;
    }
  }

  return BST;
}

/****
* PSEUDOCODE:
*  Goals:
*  - Takes a string and inserts it into a vector
*  Algorithm:
*    Declare stringstream
*    while(stringstream reads in values)
*      Insert the value into a vector
*/

void StringToVector(std::string str, std::vector <int> &vec) {
  std::stringstream iss(str); // stringstream to traverse string
  int number; // value extracted from string (values separated by spaces)
  while(iss >> number) {
    vec.push_back(number);
  }
}

int main() {
  std::string numbersString; // string to hold numbers entered by std input
  std::vector<int> myNumbers; // vector of ints that holds the input
  
  // Get numbers from std input
  getline(std::cin,numbersString);
  StringToVector(numbersString, myNumbers);

  int size = myNumbers.size(); // number of digits

  // Put numbers into a tree
  Node* root = InsertLevelOrder(myNumbers,root, 0, size);

  // Traverse tree inorder and insert numbers into vector
  std::vector<int> myNumbersInOrder; // vector that holds numbers in inorder traversal
  InOrder(root,myNumbers,myNumbersInOrder);

  if(IsBST(myNumbersInOrder)) {
    std::cout << "True";
  } else {
    std::cout << "False";
  }
}
