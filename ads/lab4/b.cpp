#include <iostream>
#include <vector>

using namespace std;

class BST {    
    public:
        struct Node {
            int val;
            Node* left;
            Node* right;

            Node(int val): val(val), left(nullptr), right(nullptr) {}
        };
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
            
            return NULL;
        }

        int subtree_size(Node* node) {
            if (node == nullptr) {
                return 0;
            }

             return 1 + subtree_size(node->left) + subtree_size(node->right);
        }

    private:

        Node* root;

        Node* insert(Node* node, int val) {
            if (node == nullptr) {
                return new Node(val);
            }

            if (val < node->val) {
                node->left = insert(node->left, val);
            }
            else if (val > node->val) {
                node->right = insert(node->right, val);
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

    cin >> val;

    BST::Node* parent = bst.find(val);

    cout << bst.subtree_size(parent) << endl;


    return 0;
}