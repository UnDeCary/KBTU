#include <iostream>

using namespace std;

class list {
    private:
        struct Node {
            int data;
            Node* next;

            Node(int val) : data(val), next(nullptr) {}
        };

        Node* head;
        Node* tail;
        int size;

    public:
        list(): head(nullptr), tail(nullptr), size(0) {}
        ~list() { clear(); }

        void push(int val) {
            size++;
            if ((size)%2 == 0) {
                return;
            }

            Node* n = new Node(val);

            if (!head) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
        }

        void print() {
            Node* cur = head;
            while (cur) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << endl;
        }


        void clear() {
            Node* cur = head;
            while (cur) {
                Node* tmp = cur;
                cur = cur->next;
                delete tmp;
            }

            head = nullptr;
            tail = nullptr;
            size = 0;
        }

};


int main() {
    int n;
    list l;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        l.push(val);
    }

    l.print();
}