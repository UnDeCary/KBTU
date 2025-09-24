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
        int size;

    public:
        List(): head(nullptr), size(0) {}

        void insert(int val, int position) {
            Node* newNode = new Node(val);
            Node* cur = head;
            Node* prev;

            size++;

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

            size--;

            if (position == 0) {
                head = cur->next;
                return;
            }

            while (cur && position != 0) {
                prev = cur;
                cur = cur->next;
                position--;
            }

            prev->next = cur->next;
            delete cur;
            return;
        }

        void print() {
            Node* cur = head;

            while (cur) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << endl;
            return;
        }

        void replace(int pos1, int pos2) {
            Node* from;
            Node* cur = head;
            Node* prev;
            if (pos1 == 0) {
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

        void reverse() {
            Node* prev = nullptr;
            Node* cur = head;
            Node* next;
            while (cur) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            head = prev;
            return;
        }

        void cyclic_left(int shift) {
            Node* cur = head;
            Node* shifted;
            Node* tail;

            shift %= size;
            if (shift == 0) return;

            for (int i = 1; i < shift; i++) {
                cur = cur->next;
            }
            
            shifted = cur->next;
            cur->next = nullptr;
            tail = shifted;

            while (tail->next) {
                tail = tail->next;
            }

            tail->next = head;
            head = shifted;

            return;
        }

        void cyclic_right(int shift) {
            Node* cur = head;
            Node* shifted;
            Node* tail;

            shift %= size;
            if (shift == 0) return;

            int to_head = size - shift;

            for (int i = 1; i < to_head; i++) {
                cur = cur->next;
            }

            shifted = cur->next;
            cur->next = nullptr;

            tail = shifted;


            while (tail->next) {
                tail = tail->next;
            }

            tail->next = head;
            head = shifted;
            return;
        }
};


int main() {
    int op, pos, pos2, val;
    List list;

    cin >> op;

    while (op != 0) {
        if (op == 1) {
            cin >> val >> pos;
            list.insert(val, pos);
        }
        else if (op == 2) {
            cin >> pos;
            list.remove(pos);
        }
        else if (op == 3) {
            list.print();
        }
        else if (op == 4) {
            cin >> pos >> pos2;
            list.replace(pos, pos2);
        }
        else if (op == 5) {
            list.reverse();
        }
        else if (op == 6) {
            cin >> val;
            list.cyclic_left(val);
        }
        else if (op == 7) {
            cin >> val;
            list.cyclic_right(val);
        }

        cin >> op;
    }


    return 0;
}
