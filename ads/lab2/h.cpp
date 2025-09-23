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

    public:
        List(): head(nullptr) {}

        void insert(int val, int position) {
            Node* newNode = new Node(val);
            Node* cur = head;
            Node* prev;
            if (position == 0) {
                newNode->next = head;
                head = newNode;
                return;
            }

            while (cur && position!=0) {
                prev = cur; 
                cur = cur->next;
                position--;
            }

            newNode->next = cur;
            prev-> next = newNode;
            return;
        }

        void remove(int position) {
            Node* cur = head;
            Node* prev;
            if (position == 0) {
                head = cur->next;
                return;
            }

            while (cur && position != 0) {
                prev = cur;
                cur = cur->next;
            }

            prev->next = cur->next;
            delete cur;
        }

        void print() {
            Node* cur = head;

            while (cur) {
                cout << cur->val << " ";
                cur = cur->next;
            }
            cout << endl;
            return;
        }

        void replace(int pos1, int pos2) {
            Node* from;
            Node* cur = head;
            Node* prev;
            if (pos1) {
                from = cur;
                head = cur->next;
            }

            else {
                while (cur && pos1 > 0) {
                    prev = cur;
                    cur = cur->next;
                    pos1--;
                }
                from = cur;
                prev->next = cur->next; 

            }

            cur = head;

            if (pos2 == 0) {
                head = from;
                from->next = cur;
                return; 
            }

            while (cur && pos2 > 0) {
                prev = cur;
                cur = cur->next;
                pos2--;
            }
            
            from->next = prev->next;
            prev->next = from;
            return;
        }
}
