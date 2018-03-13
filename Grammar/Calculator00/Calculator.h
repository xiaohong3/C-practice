#include "./Token.h";

class Calculator {
    public:
    Token get_token();
    double expression();
    double term();
    double primary();
};