#include <iostream>

using namespace std;

int LCA(int root, int p, int q) {
    if (!root) {
        return -1;
    } 
    if (p < root->val && q < root) {
        retunr LCA(root->left, p, q);
    }

    else if (p > root && q > root) {
        return LCA(root->right, p, q);
    }
    else {
        return root;
    }
}


int main() {
    int root, p, q;

    cin >> root >> p >> q;

    LCA(root, p, q);
    return 0;
}
