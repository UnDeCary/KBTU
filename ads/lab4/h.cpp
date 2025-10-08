#include <iostream>
#include <vector>

using namespace std;

class BST {    
    public:
        
        struct Node {
            int val;
            int cnt;
            Node* left;
            Node* right;

            Node(int val): val(val), cnt(1), left(nullptr), right(nullptr) {}
        };

        Node* root;

        BST(): root(nullptr) {}

        void insert(int val) {
            root = insert(root, val);
        }

        Node* find(int val) {
            Node* node = root;

            while (node) {
                if (val < node->val) {
                    node = node->left;
                }
                else if (val > node->val) {
                    node = node->right;
                }
                else {
                    return node;
                }
            }
            
            return nullptr;
        }
        int sum = 0;


        void toGST(Node* node) {
            if (!node) return;

            toGST(node->right);
            sum += node->val;
            node->val = sum;
            toGST(node->left);
        }

        void inorder(Node* node) {
            if (!node) return;
            inorder(node->right);
            cout << node->val << " ";
            inorder(node->left);
        }

    private:

        Node* insert(Node* node, int val, int level = 0) {
            if (node == nullptr) {
                return new Node(val);
            }

            if (val < node->val) {
                node->left = insert(node->left, val, level+1);
            }
            else if (val > node->val) {
                node->right = insert(node->right, val, level+1);
            }
            else {
                node->cnt++;
            }

            return node;
        }
};

int main() {
    int n, val;
    cin >> n;
    BST bst;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        bst.insert(val);
    }

    bst.toGST(bst.root);
    bst.inorder(bst.root);
    cout << endl;

    return 0;
}