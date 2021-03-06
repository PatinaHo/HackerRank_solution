/* Subdomain: Trees
 * Problem: Tree: Level Order Traversal
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

    void levelOrder(node * root) {
        std::queue<node*> q;
        q.push(root);            //先把root丟進queue裡

        while(q.empty() != 1){   //若queue不是空的, 表示還有node沒拜訪
            node* current = q.front();
            cout << current->data << " ";
            if (current->left != NULL){
                q.push(current->left);
            }
            if (current->right != NULL){
                q.push(current->right);
            }
            q.pop();
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
  
    myTree.levelOrder(root);

    return 0;
}
