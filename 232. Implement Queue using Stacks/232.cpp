#include <stack>
#include <iostream>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stk1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!stk2.empty())
        {
            stk2.pop();
            return;
        }
        //栈1的元素出栈 压入栈2
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.pop();
        return;
    }

    // Get the front element.
    int peek(void) {
        if(!stk2.empty())
            return stk2.top();
        //栈1的元素出栈 压入栈2
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk1.empty() && stk2.empty();
    }
private:
    stack<int> stk1;        //负责入队列
    stack<int> stk2;        //负责出队列
};

int main()
{
    Queue q;
    q.push(1);
    cout << q.peek() << endl;
    q.push(2);
    q.pop();
    cout << q.peek() << endl;
    q.push(3);
    q.pop();
    cout << q.peek() << endl;

}
