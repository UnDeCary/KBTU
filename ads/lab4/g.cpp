#include <iostream>
#include <vector>

using namespace std;

class BST {    
    public:
        int triangles = 0;
        
        struct Node {
            int val;
            Node* left;
            Node* right;

            Node(int val): val(val), left(nullptr), right(nullptr) {}
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

        int diameter = 0;

        int height(Node* node) {
            if (node == nullptr) {
                return 0;
            }

            int hl = height(node->left);
            int hr = height(node->right);
            diameter = max(diameter, hl + hr + 1);
            return max(hl, hr) + 1;
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


    bst.height(bst.root);

    cout << bst.diameter << endl;


    return 0;
}