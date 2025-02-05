/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

#include <iostream> 
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;

        for (int i = 0; i<s.length(); i++) {
            // opening bracket
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sk.push(s[i]);
            }
            // close bracker
            else {
                // first char cant be vlose bracket
                if (sk.empty()) {
                    return false;
                }
                // correct pair found then pop
                else if (s[i] == ')' && sk.top() == '(') {
                    sk.pop();
                }
                else if (s[i] == '}' && sk.top() == '{') {
                    sk.pop();
                }
                else if (s[i] == ']' && sk.top() == '[') {
                    sk.pop();
                }
                // not found means there is no correct parentheses
                else {
                    return false;
                }
            }
        }
        // stack is empty means all char is matched up
        if (sk.empty()) return true;
        // not all pairs are matched up
        return false;   
    }
};