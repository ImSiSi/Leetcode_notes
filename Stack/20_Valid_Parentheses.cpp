#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        if (s.size() % 2 == 1)
            return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{')
                temp.push('}');
            else if (s[i] == '[')
                temp.push(']');
            else if (s[i] == '(')
                temp.push(')');
            else if (temp.empty() || temp.top() != s[i])
                return false;
            else
                temp.pop();
        }
        return temp.empty();
    }
};

int main() {
    Solution sol;
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([{}])";
    string test5 = "({[)]}";
    string test6 = "[";

    cout << test1 << " -> " << (sol.isValid(test1) ? "true" : "false") << endl;
    cout << test2 << " -> " << (sol.isValid(test2) ? "true" : "false") << endl;
    cout << test3 << " -> " << (sol.isValid(test3) ? "true" : "false") << endl;
    cout << test4 << " -> " << (sol.isValid(test4) ? "true" : "false") << endl;
    cout << test5 << " -> " << (sol.isValid(test5) ? "true" : "false") << endl;
    cout << test6 << " -> " << (sol.isValid(test6) ? "true" : "false") << endl;

    return 0;
}