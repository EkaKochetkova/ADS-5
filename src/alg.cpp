// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int pr(char operation) {
    switch (operation) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '-':
        return 2;
    case '+':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    case ' ':
        return 4;
    default:
        return 5;
    }
}
int calc(char operation, int a, int b) {
    switch (operation) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}
std::string infx2pstfx(std::string inf) {
    std::string result;
    TStack <char, 100> stack;
    for (int i = 0; i < inf.length(); i++) {
        if (pr(inf[i]) == 5) {
            result.push_back(inf[i]);
            result.push_back(' ');
        } else {
            if (pr(inf[i]) == 4) {
                continue;
            } else if (pr(inf[i]) > pr(stack.get())) {
                stack.push(inf[i]);
            } else if (pr(inf[i]) == 0) {
                stack.push(inf[i]);
            } else if (stack.isEmpty()) {
                stack.push(inf[i]);
            } else if (pr(inf[i]) == 1) {
                while (pr(stack.get()) != 0) {
                    result.push_back(stack.get());
                    result.push_back(' ');
                    stack.pop();
                }
                stack.pop();
            } else {
                while (!stack.isEmpty() && (pr(inf[i]) <= pr(stack.get()))) {
                    result.push_back(stack.get());
                    result.push_back(' ');
                    stack.pop();
                }
                stack.push(inf[i]);
            }
        }
    }
    while (!stack.isEmpty()) {
        result.push_back(stack.get());
        result.push_back(' ');
        stack.pop();
    }
    result.pop_back();
    return result;
}
int eval(std::string pref) {
    TStack <int, 100> stack;
    int result = 0;
    int b = 0;
    int a = 0;
    for (int i = 0; i < pref.length(); i++) {
        if (pr(pref[i]) == 4) {
            stack.push(pref[i] - '0');
        } else if (pr(pref[i]) < 4) {
            b = stack.get();
            stack.pop();
            a = stack.get();
            stack.pop();
            stack.push(calc(pref[i], a, b));
        }
    }
    result = stack.get();
    return result;
}
