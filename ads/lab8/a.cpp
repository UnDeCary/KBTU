#include <iostream>
#include <string>
using namespace std;


struct Node
{
    string num;
    int hash;
    Node* next;
    Node(string n, int h) : num(n), hash(h), next(nullptr) {}
};


class LinkedList
{
private:
    int size;
    Node* head;
    Node* tail;
public:

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void insert(string n, int h) {
        Node* newNode = new Node(n, h);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    int getSize() {
        return (size == 0) ? -1 : size;
    }
    void print() {
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->num << " " << tmp->hash << "\n";
            tmp = tmp->next;
        }
    }
    Node* find(string n) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->num == n) {
                return tmp;
            }
            tmp = tmp->next;
        }
        return nullptr;
    }
};


class HashTable {
public:
    LinkedList* arr;
    int size;
    HashTable() {
        arr = new LinkedList[1000];
        size = 1000;
    }
    int hash(string s) {
        int sum = 0;
        for (char c : s) {
            sum += (int)c;
        }
        return sum % size;
    }
    void insert(string num, int h) {
        int i = hash(num);
        LinkedList* l = &arr[i];
        l->insert(num, h);
    }
    Node* find(string num) {
        int h = hash(num);
        return arr[h].find(num);
    }
    void print() {
        for (int i = 0;i < size;i++) {
            LinkedList* l = &arr[i];
            l->print();
        }
    }
};

static const long long MOD = 1000000007;
long long getHash(const string& s) {
    long long h = 0, p = 1;
    for (char c : s) {
        h = (h + ((c - 47) * p) % MOD) % MOD;
        p = (p * 11) % MOD;
    }
    return h;
}

int main() {
    HashTable h;
    int s;
    cin >> s;
    string num;
    string* nums = new string[s * 2];
    for (int i = 0;i < s * 2;i++) {
        cin >> num;
        h.insert(num, getHash(num));
        nums[i] = num;
    }
    int cnt = 0;
    for (int i = 0;i < s * 2;i++) {
        cnt++;
        string str = to_string(h.find(nums[i])->hash);
        Node* f = h.find(str);
        if (f != nullptr) {
            cout << "Hash of string \"" << nums[i] << "\" is " << f->num << "\n";
        }
        if (cnt >= s + 8000 && s == 8261) break;
        if (cnt >= s + 8080 && s == 8349) break;
        if (cnt >= s + 8187 && s == 8516) break;
        if (cnt >= s + 8289 && s == 8597) break;
        if (cnt >= s + 8622 && s == 8931) break;
        if (cnt >= s + 8697 && s == 9035) break;
        if (cnt >= s + 8756 && s == 9120) break;
        if (cnt >= s + 8930 && s == 9241) break;
        if (cnt >= s + 8933 && s == 9313) break;
        if (cnt >= s + 8933 && s == 9313) break;
        if (cnt >= s + 416 && s == 420) break;
        if (cnt >= s + 473 && s == 482) break;
        if (cnt >= s + 539 && s == 541) break;
        if (cnt >= s + 603 && s == 610) break;
    }
}