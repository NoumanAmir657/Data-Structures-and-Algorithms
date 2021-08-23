#include <iostream>
#include "stack.h"
#include <string>

bool checkBraces(); // application
void infinixToPostfix(); //application
int getPrecedence(char); //utility function

int main (){
    //checkBraces();
    //infinixToPostfix();
    std::cin.get();
    return 1;
}

// Application of Stack
bool checkBraces() {
    Stack <char> stack;
    std::string exp = "1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + 14";

    for(int i = 0; i < exp.size(); ++i){
        char c = exp[i];
        if (c == '(' || c == '[' || c == '{'){
            stack.push(exp[i]);
        }
        else if (c == ')' || c == ']' || c == '}'){
            char temp = stack.pop();
            if (temp == '(' && c == ')' || temp == '{' && c == '}' || temp == '[' && c == ']'){
                continue;
            }
            else {
                break;
            }
        }
    }

    if (stack.isEmpty()){
        std::cout << "Braces are balanced\n";
    }
    else {
        std::cout << "The Braces are not balanced\n";
    }

    return false;
}

// Application of Stack
void infinixToPostfix() {
    Stack<char> stack;
    std::string infinix = "{2*(430+10)}^3";
    std::string postfix = "";

    for(int i = 0; i < infinix.size(); ++i){
        char c = infinix[i];
        if (isalnum(c)){
            postfix+=c;
        }
        else if(c == '^'){
            stack.push(c);
            postfix+=" ";
        }
        else if(c == '(' || c == '[' || c == '{'){
            stack.push(c);
        }
        else if(c == ')' || c == ']' || c == '}'){
            char temp = stack.pop();
            while (temp != '(' && temp != '{' && temp != '[' && !stack.isEmpty()){
                postfix+=temp;
                temp = stack.pop();
            }
        }
        else {
            postfix+=' ';
            if (getPrecedence(c) > getPrecedence(stack.peek())){
                stack.push(c);
            }
            else if(getPrecedence(c) <= getPrecedence(stack.peek())){
                char temp = stack.pop();
                if (stack.isEmpty()){
                    postfix+=temp;
                }
                while (temp != '(' && temp != '{' && temp != '[' && !stack.isEmpty()){
                    postfix+=temp;
                    temp = stack.pop();
                }
                stack.push(c);   
            }
        }
    }

    while(!stack.isEmpty()){
        postfix+=stack.pop();
    }
    std::cout << postfix;
}

int getPrecedence(char c) {
    if (c == '+' || c == '-'){
        return 0;
    }
    else if(c == '/' || c == '*'){
        return 1;
    }
    else if(c == '^'){
        return 2;
    }
    else {
        return -1;
    }
}