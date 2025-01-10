#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "7+5*(-6)"; // Example with spaces before unary minus

    // Operator precedence mapping
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

        // Handle numbers (digits)
        if (isdigit(c)) {
            int num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            nums.push(num);
            --i; // Decrement i to avoid skipping the next character
        }
        // Handle '('
        else if (c == '(') {
            ops.push(c); // Push '(' to operators stack
        }
        // Handle ')'
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                
                if (op == '+') nums.push(a + b);
                else if (op == '-') nums.push(a - b);
                else if (op == '*') nums.push(a * b);
                else nums.push(a / b);
            }
            ops.pop(); // Pop '(' from operators stack
        }
        else {  // Handle operators ('+', '-', '*', '/')
            // Handle unary minus: If it's at the start or after '(' or other operators
            if (c == '-' && (i == 0 || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/')) {
                int num = 0;
                ++i; // Move to the next character after the '-'
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(-num); // Push the negative number to the stack
                --i; // Decrement i to avoid skipping the next character
            } else {
                // Process regular operators (handle precedence)
                while (!ops.empty() && ops.top() != '(' && precedence[c] <= precedence[ops.top()]) {
                    int b = nums.top(); nums.pop();
                    int a = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();
                    
                    if (op == '+') nums.push(a + b);
                    else if (op == '-') nums.push(a - b);
                    else if (op == '*') nums.push(a * b);
                    else nums.push(a / b);
                }
                ops.push(c); // Push the operator to the stack
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

    // The final result is the only number left in the stack
    cout << nums.top() << endl; // Print the final result

    return 0;
}
