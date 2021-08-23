#include <iostream>
#include "stack.h"
#include <string>

bool checkBraces(); // application

int main (){
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