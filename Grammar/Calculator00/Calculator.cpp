#include "./Calculator.h"
#include "./Token.h"

double Calculator::expression() {
    double left = term();
    Token t = get_token();
    while(true) {
        switch(t.kind) {
            case '+':
            left += term();
            t = get_token();
            break;

            case '-':
            left -= term();
            t = get_token();
            break;

            default:
            return left;
        }
    }
}

double Calculator::term() {
    double left = primary();
    Token t = get_token();
}

double Calculator::primary() {}

Token Calculator::get_token() {}