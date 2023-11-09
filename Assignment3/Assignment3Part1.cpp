#include <iostream>
#include <stack>
#include <string>
using namespace std;


/*
INPUT: char
OUTPUT: boolean value. returns true if it is between A and Z or a and z, false otherwise.
*/
bool func1(char thing) {
    if ((thing >= 'a' && thing <= 'z') || (thing >= 'A' && thing <= 'Z'))
        return true;
    else
        return false;
}

/*
INPUT: char
OUTPUT: boolean value. returns true if it is equal to +, -, *, /, or %, false otherwise.
*/
bool func2(char thing) {
    if (thing == '+' || thing == '-' || thing == '*' || thing == '/' || thing == '%')
        return true;
    else
        return false;
}

/*
INPUT: char
OUTPUT: an integer based on the precedence of the operator based on the order of operations. 2 if *, /, or %; 1 if +,-; otherwise returns 0.
*/

int pemdas(char thing) {
    if (thing == '*' || thing == '/' || thing == '%')
        return 2;
    if (thing == '+' || thing == '-')
        return 1;
    return 0;
}


bool Balanced(string thing2) {
    stack<char> stack1;
    for (char thing : thing2) {
        if (thing == '(' || thing == '{' || thing == '[') {
            stack1.push(thing);
        }
        else 
            if (thing == ')' || thing == '}' || thing == ']') {
                if (stack1.empty())
                    return false;

                char openBracket = stack1.top();
                stack1.pop();
                if ((thing == ')' && openBracket != '(') || (thing == '}' && openBracket != '{') || (thing == ']' && openBracket != '[')) {
                    return false;
                }
            }
    }
    return stack1.empty();
}

/*
INPUT: string representing infix equation
OUTPUT: string representing same postfix equation
*/

string infixToPostfix(string infix) {
    string postfix;
    stack<char> stack;

    for (char c : infix) {
        if (func1(c) == true) {
            postfix += c;
        }
        else if (func2(c) == true) {
            while (!stack.empty() && pemdas(stack.top()) >= pemdas(c)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    if (Balanced(infixExpression)) {

    }
    else {
        cout << "Invalid!\n";
        return 0;
    }

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfix: " << postfixExpression << endl;

    return 0;
}
