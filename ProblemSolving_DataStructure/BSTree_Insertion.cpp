/* Subdomain: Trees
 * Problem: Binary Search Tree : Insertion
 */

#include <iostream>
#include <cstddef>
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  
    void preOrder(Node *root) {

          if( root == NULL )
              return;

          std::cout << root->data << " ";

          preOrder(root->left);
          preOrder(root->right);
      }

    node * insert(node * root, int value) {
        if (root == NULL){
            root = new node();
            root->data = value;
            root->left = NULL;
            root->right = NULL;
        }
        else if (root->data > value){
            root->left = insert(root->left, value);
        }
        else if (root->data < value){
            root->right = insert(root->right, value);
        }

      return root;
    }
};

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  myTree.preOrder(root);
    return 0;
}