#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> que1;
    queue<int> que2;
public:
    MyStack() {}

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        while (que1.size() > 1) {
            que2.push(que1.front());
            que1.pop();
        }
        int res = que1.front();
        que1.pop();
        swap(que1, que2); 
        return res;
    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << "Top: " << stack.top() << endl;    
    cout << "Pop: " << stack.pop() << endl;    
    cout << "Empty: " << (stack.empty() ? "true" : "false") << endl; 
    cout << "Pop: " << stack.pop() << endl;    
    cout << "Empty: " << (stack.empty() ? "true" : "false") << endl; 
    return 0;
}