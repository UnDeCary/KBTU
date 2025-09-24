#include <iostream>

using namespace std;

class List {
    private:
        struct Node {
            int data;
            Node* next;

            Node(int val): data(val), next(nullptr) {}
        };

        Node* head;
        Node* tail;

    public:
        List(): head(nullptr), tail(nullptr) {}

        void add(int val) {
            Node* newNode = new Node(val);

            if (!head) {
                head = newNode;
                tail = newNode;
                return;
            }

            Node* last = tail;

            tail = newNode;
            last->next = tail;
        }

        void insert(int val, int index) {
            Node* newNode = new Node(val);
            Node* cur = head;
            Node* prev = nullptr;

            if (index == 0) {
                Node* temp = head;
                head = newNode;
                head->next = temp;
                return;
            }

            while (index > 0 && cur) {
                prev = cur;
                cur = cur->next;
                index--;
            }
            
            prev->next = newNode;
            newNode->next = cur;
        }

        void print() {
            Node* cur = head;
            while (cur) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << endl;
        }
};


int main() {
    int n, val, index;
    List list;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        list.add(val);
    }

    cin >> val >> index;

    list.insert(val, index);

    list.print();

    return 0;
}