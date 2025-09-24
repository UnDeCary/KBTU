#include <iostream>

using namespace std;

class db {
    private:
        struct Node {
            string data;
            Node* next;

            Node(string val): data(val), next(nullptr) {}
        };

        Node* head;

    public:
        int size;
        
        db(): head(nullptr), size(0) {}

        void add(string val) {
            Node* newNode = new Node(val);
            Node* tmp = head;
            if (!head) {
                head = newNode;
                size++;
                return;
            }

            if (head->data == val) {
                return;
            }

            head = newNode;
            head->next = tmp;
            size++;
        }

        void print() {
            Node* cur = head;
            while (cur) {
                cout << cur->data << endl;
                cur = cur->next;
            }
        }
};


int main() {
    int n;
    string val;
    db students;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        students.add(val);
    }

    cout << "All in all: " << students.size << endl << "Students:" << endl;
    students.print();


    return 0;
}