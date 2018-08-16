/* Subdomain: Trees
 * Problem: Tree: Height of a Binary Tree
 */

#include <bits/stdc++.h>

using namespace std;

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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

    int height(Node* root) {
        // Write your code here.
        int h = 0;
        if (root == NULL)
            return 0;
        else if (root->left == NULL && root->right == NULL)
            return 0;
        else{
            int hLeft = height(root->left);
            int hRight = height(root->right);
            if (hLeft >= hRight)
                h = hLeft + 1;
            else
                h = hRight + 1;
            return h;
        }
    }
}; //End of Solution

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
  
    int height = myTree.height(root);
    std::cout << height;

    return 0;
}