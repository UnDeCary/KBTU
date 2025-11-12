#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    int n;

    cin >> n;

    map<string, string> orig2cur;
    unordered_map<string, string> cur2orig;

    for (int i = 0; i < n; i++) {
        string old_name, new_name;
        cin >> old_name >> new_name;

        auto it = cur2orig.find(old_name);
        if (it != cur2orig.end()) {
            string original = it->second;
            cur2orig.erase(it);
            cur2orig[new_name] = original;
            orig2cur[original] = new_name;
        }
        else {
            cur2orig[new_name] = old_name;
            orig2cur[old_name] = new_name;
        }

    }

    cout << orig2cur.size() << endl;
    for (auto item : orig2cur) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}