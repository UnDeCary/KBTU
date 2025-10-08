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


        void delete_node(int val) {
            root = delete_node(root, val);
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

        Node* delete_node(Node* node, int val) {
            if (!node) return nullptr;

            if (val < node->val) {
                node->left = delete_node(node->left, val);
            } 
            else if (val > node->val) {
                node->right = delete_node(node->right, val);
            } 
            else {
                if (node->cnt > 1) {
                    node->cnt--;
                    return node;
                }

                if (!node->left && !node->right) {
                    delete node;
                    return nullptr;
                }
                else if (!node->left) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                else if (!node->right) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                else {
                    Node* successor = findMin(node->right);
                    node->val = successor->val;
                    node->cnt = successor->cnt;
                    successor->cnt = 1;
                    node->right = delete_node(node->right, successor->val);
                }
            }
            return node;
        }

        Node* findMin(Node* node) {
            while (node->left) node = node->left;
            return node;
        }
};

int main() {
    int n;
    cin >> n;
    BST bst;

    for (int i = 0; i < n; i++) {
        string op;
        int val;
        cin >> op >> val;
        if (op == "insert") {
            bst.insert(val);
        }
        else if (op == "delete") {
            bst.delete_node(val);
        }
        else if (op == "cnt") {
            BST::Node* node = bst.find(val);
            if (!node) {
                cout << 0 << endl;
                continue;
            }
            cout << node->cnt << endl;
        }
    }

     
    cout << endl;

    return 0;
}