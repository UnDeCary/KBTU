# include <iostream>
# include <algorithm>
# include <cassert>
# include <climits>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
    int maxMax = 0;
	int max = 0;
    int maxVal = INT_MIN;

    Node* cur = head;

    while (cur) {
        if (maxVal < cur->val) {
            maxVal = cur->val;
        }
        if (max + cur->val < 0) {
            max = 0;
            cur = cur->next;
            continue;
        }

        max += cur->val;

        if (max > maxMax) {
            maxMax = max;
        }
        cur = cur->next;
        
    }
    if (maxMax == 0) {
        maxMax = maxVal;
    }

    return maxMax;
	
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
