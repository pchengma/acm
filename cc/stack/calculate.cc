// LeetCode: 227. Basic Calculator II (Medium)
class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0) {
            return 0;
        }

        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';

        for (int i = 0; i < s.length(); ++i) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }

            if (!isdigit(currentChar) && !iswspace(currentChar) || i == s.length() - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }

        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};