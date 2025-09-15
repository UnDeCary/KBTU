#include <iostream>
using namespace std;

class List {
    private:
        struct Node {
            int data;
            Node* next;

            Node(int val) : data(val), next(nullptr) {}
        };

        Node* head;

    public:
        List(): head(nullptr) {}
        ~List() { clear(); }

        void push_front(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        void push_back(int val) {
            Node* newNode = new Node(val);
            if (!head) {
                head = newNode;
                return;
            }

            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }

        void print() {
            Node* cur = head;
            while (cur) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << endl;
        }

        void reverse() {
            Node* prev = nullptr;
            Node* cur = head;

            while (cur) {
                Node* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            head = prev;
        }

        void clear() {
            Node* cur = head;
            while (cur) {
                Node* tmp = cur;
                cur = cur->next;
                delete tmp;
            }

            head = nullptr;
        }
};


int main() {
    List list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.print();
    list.reverse();
    list.print();


    return 0;
}