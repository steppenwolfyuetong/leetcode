#include <queue>
#include <iostream>
using namespace std;

class Stack {
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for(int i = 0; i < que.size() - 1; i++)
        {
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};

int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    cout << stk.top() << endl;
    cout << stk.empty() << endl;
    stk.pop();
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.empty() << endl;
    return 0;
}
