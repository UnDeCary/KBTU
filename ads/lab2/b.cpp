#include <iostream>
#include <queue>

using namespace std;


int main() {
    int n, k;
    string word;
    queue<string> poem;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> word;
        poem.push(word);
    }

    for (int i = 0; i < k; i++) {
        word = poem.front();
        poem.pop();
        poem.push(word);
    }

    for (int i = 0; i < n; i++) {
        cout << poem.front() << " ";
        poem.pop();
    }

    return 0;
}