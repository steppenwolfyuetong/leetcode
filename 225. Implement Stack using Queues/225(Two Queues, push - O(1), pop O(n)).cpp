#include <queue>
#include <iostream>
using namespace std;

class Stack {
public:
    queue<int> que1,que2;
    // Push element x onto stack.
    void push(int x) {
        que1.push(x);
	
    }

    // Removes the element on top of the stack.
    void pop() {
    	int size = que1.size();
		for(int i = 0; i < size - 1; i++)
		{
			que2.push(que1.front());
			que1.pop();
		}
		que1.pop();
		swap(que1,que2);
    }

    // Get the top element.
    int top() {
        int size = que1.size();
        for(int i = 0; i < size - 1; i++)
        {
        	que1.push(que1.front());
        	que1.pop();
		}
		int rt = que1.front();
		que1.push(que1.front());
        que1.pop();
        return rt;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que1.empty();
    }
};

int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;
    cout << stk.empty() << endl;
    stk.pop();
    cout << stk.empty() << endl;

    return 0;
}
