#include <iostream>

using namespace std;

template <typename T>
class List {
    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;

            Node(T val): data(val), next(nullptr), prev(nullptr) {}
        };

        Node* head;
        Node* tail;

    public:
        List(): head(nullptr), tail(nullptr) {}


        void add_front(T val) {
            Node* newNode = new Node(val);
            Node* cur = head;

            if (!head) {
                tail = newNode;
            }

            head = newNode;
            head->next = cur;
            if (cur) {
                cur->prev = head;
            }

            return;
        }

        void add_back(T val) {
            Node* newNode = new Node(val);
            Node* cur = tail;

            if (!tail) {
                head = newNode;
            }

            tail = newNode;
            tail->prev = cur;
            if (cur) {
                cur->next = tail;
            }
            return;
        }

        void erase_front() {
            if (!head) {
                cout << "error" << endl;
                return;
            }

            Node* cur = head->next;
            cout << head->data << endl;
            delete head;
            head = cur;

            if (cur) {
                cur->prev = nullptr;
                return;
            }
            tail = nullptr;
            return;            
        }

        void erase_back() {
            if (!tail) {
                cout << "error" << endl;
                return;
            }

            Node* cur = tail->prev;
            cout << tail->data << endl;
            delete tail;
            tail = cur;

            if (cur) {
                cur->next = nullptr;
                return;
            }
            head = nullptr;
            return;            
        }

        void front() {
            if (!head) {
                cout << "error" << endl;
                return;
            }
            cout << head->data << endl;
            return;
        }

        void back() {
            if (!tail) {
                cout << "error" << endl;
                return;
            }
            cout << tail->data << endl;
            return;
        }

        void clear() {
            Node* cur = head;

            while (cur) {
                Node* next = cur->next;
                delete cur;
                cur = next;
            }

            head = nullptr;
            tail = nullptr;

            return;
        }
        
};


int main() {
    string op, val;
    List<string> list;

    cin >> op;

    while (op != "exit") {
        if (op == "add_front") {
            cin >> val;
            list.add_front(val);
            cout << "ok" << endl;
        }
        else if (op == "add_back") {
            cin >> val;
            list.add_back(val);
            cout << "ok" << endl;
        }
        else if (op == "erase_front") {
            list.erase_front();
        }
        else if (op == "erase_back") {
            list.erase_back();
        }
        else if (op == "front") {
            list.front();
        }
        else if (op == "back") {
            list.back();
        } 
        else if (op == "clear") {
            list.clear();
            cout << "ok" << endl;
        }

        cin >> op;
    }

    cout << "goodbye" << endl;
    return 0;
}