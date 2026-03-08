class Solution {
public:
    bool isValid(string s) {

        // Using stack to check valid parentheses
        // We traverse the string and push opening brackets into the stack
        // When a closing bracket appears, we check the top of stack for its
        // matching opening bracket If it matches we pop the stack, otherwise we
        // push the current character At the end if the stack is empty then the
        // string is valid otherwise it is invalid Time Complexity - O(n) Space
        // Complexity - O(n)

        stack<char> st;
        for (char ch : s) {
            if (!st.empty() && ch == ')' && st.top() == '(') {
                cout << ch << endl;
                st.pop();
            } else if (!st.empty() && ch == '}' && st.top() == '{') {
                cout << ch << endl;
                st.pop();
            } else if (!st.empty() && ch == ']' && st.top() == '[') {
                cout << ch << endl;
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return st.size() > 0 ? false : true;
    }
};