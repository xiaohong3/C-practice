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
    while(true) {
        switch(t.kind) {
            case '*':
            left *= primary();
            t = get_token();
            break;

            case '/': {
                double d = primary();
                if (d == 0) {
                    error("Divided by zero");
                }
                left /= primary();
                t = get_token();
                break;
            }

            default:
            return left;
        }
    }
}

double Calculator::primary() {
    Token t = get_token();
    switch(t.kind) {
        case '(': {
            double d = expression();
            t = get_token();
            if (t.kind != ')') {
                error(") expected");
            }
            return d;
        }

        case '8':
        return t.value;

        default:
        error("primary expected");
    }
}

Token Calculator::get_token() {
    char ch;
    cin >> ch;
    switch(ch) {
        case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);

        case '.':
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9': {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token('8', val);
        }

        default:
        error("Bad token!");
    }

}