#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    
    MyQueue() {}
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int t = stOut.top();
        stOut.pop();
        return t;
    }
    
    int peek() {
        int t = this->pop();
        stOut.push(t);
        return t;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "Peek: " << q.peek() << endl;    // 應輸出 1
    cout << "Pop: " << q.pop() << endl;      // 應輸出 1
    cout << "Empty: " << (q.empty() ? "true" : "false") << endl; // 應輸出 false
    cout << "Pop: " << q.pop() << endl;      // 應輸出 2
    cout << "Empty: " << (q.empty() ? "true" : "false") << endl; // 應輸出 true
    return 0;
}