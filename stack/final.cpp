#include <bits/stdc++.h>
using namespace std;

int evaluateExpression(string s) {
    map<char, int> precedence = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
    };

    stack<int> nums; // Stack for numbers
    stack<char> ops; // Stack for operators

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (isspace(c)) {
            continue; // Skip whitespace
        }

        // Handle numbers
        if (isdigit(c)) {
            int num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            nums.push(num);
            --i; // Decrement to avoid skipping the next character
        } 
        // Handle '(', '[', and '{'
        else if (c == '(' || c == '[' || c == '{') {
            ops.push(c);
        }
        // Handle ')', ']', and '}'
        else if (c == ')' || c == ']' || c == '}') {
            char open = (c == ')') ? '(' : (c == ']') ? '[' : '{';
            while (!ops.empty() && ops.top() != open) {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();

                if (op == '+') nums.push(a + b);
                else if (op == '-') nums.push(a - b);
                else if (op == '*') nums.push(a * b);
                else if (op == '/') nums.push(a / b);
            }
            ops.pop(); // Pop the opening bracket
        } 
        else {
            // Handle unary minus: Check if the current operator is '-' and it's after '(', or it's the start of the string
            if (c == '-' && (i == 0 || s[i-1] == '(' || s[i-1] == '+' || s[i-1] == '-' || s[i-1] == '*' || s[i-1] == '/')) {
                // Handle the unary minus: Look ahead for the number
                int num = 0;
                ++i; // Move to the next character to process the number
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(-num); // Push the negative number
                --i; // Decrement to avoid skipping the next character
            } else {
                // Handle regular operators '+', '-', '*', '/'
                while (!ops.empty() && ops.top() != '(' && ops.top() != '[' && ops.top() != '{' &&
                       precedence[c] <= precedence[ops.top()]) {
                    int b = nums.top(); nums.pop();
                    int a = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();

                    if (op == '+') nums.push(a + b);
                    else if (op == '-') nums.push(a - b);
                    else if (op == '*') nums.push(a * b);
                    else nums.push(a / b);
                }
                ops.push(c);
            }
        }
    }

    // Process remaining operators in the stack
    while (!ops.empty()) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();

        if (op == '+') nums.push(a + b);
        else if (op == '-') nums.push(a - b);
        else if (op == '*') nums.push(a * b);
        else nums.push(a / b);
    }

    return nums.top(); // Return the final result
}

int main() {
    string s = "5 + 4 * ( -5 )";
    cout << evaluateExpression(s) << endl;  // Output should be -15
    return 0;
}
