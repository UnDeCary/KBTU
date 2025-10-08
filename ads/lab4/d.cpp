#include <iostream>
#include <vector>

using namespace std;

class BST {    
    public:
        vector<int> levels;
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
            
            return nullptr;
        }

        void cout_subtree(Node* node) {
            if (node == nullptr) {
                return;
            }
            cout << node->val << " ";

            cout_subtree(node->left);
            cout_subtree(node->right);

            return;
        }

    private:

        Node* root;

        Node* insert(Node* node, int val, int level = 0) {
            if (node == nullptr) {
                if (levels.size() <= level) {
                    levels.push_back(val);
                }
                else {
                    levels[level] += val;
                }
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


    cout << bst.levels.size() << endl;

    for (int i = 0; i < bst.levels.size(); i++) {
        cout << bst.levels[i] << " ";
    }


    return 0;
}