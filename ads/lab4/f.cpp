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

        void count_triangles(Node* node) {
            if (node == nullptr) {
                return;
            }

            if (node->left != nullptr && node->right != nullptr) {
                triangles++;
            }

            count_triangles(node->left);
            count_triangles(node->right);

            return;
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


    bst.count_triangles(bst.root);

    cout << bst.triangles << endl;


    return 0;
}