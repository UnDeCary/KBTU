#include <iostream>
#include <vector>

using namespace std;

class BST {
    private:
        struct Node {
            int val;
            Node* left;
            Node* right;

            Node(int val): val(val), left(nullptr), right(nullptr) {}
        };

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

        
    
    public:
        BST(): root(nullptr) {}

        void insert(int val) {
            root = insert(root, val);
        }

        bool search(string direction) {
            Node* node = root;

            
            for (char i : direction) {
                if (node == nullptr) {
                    break;
                }
                if (i == 'R') {
                    node = node->right;
                }
                else if (i == 'L') {
                    node = node->left;
                }
                
            }
            if (node == nullptr) {
                return false;
            }
            return true;

        }
};

int main() {
    int n, m;
    cin >> n >> m;
    BST bst;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        bst.insert(val);
    }

    for (int i = 0; i < m; i++) {
        string direction;
        cin >> direction;
        if (bst.search(direction)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }


    return 0;
}