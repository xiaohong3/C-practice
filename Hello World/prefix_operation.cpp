#include "../std_lib_facilities.h"

int main() {
    cout << "Enter an operation and two numbers. Separated by space.\n";

    char operation = 0;
    double n1 = 0;;
    double n2 = 0;
    cin >> operation;
    cin >> n1;
    cin >> n2;
    double result = 0;

    if (operation == '+') {
        result = n1 + n2;
    } else if (operation == '-') {
        result = n1 - n2;
    } else if (operation == '/') {
        if (n2 == 0) {
            simple_error("Divider can not be 0.\n");
        }
        result = n1 / n2;
    } else if (operation == '*') {
        result = n1 * n2;
    } else {
        simple_error("Unknown operations.");
    }

    cout << "The result is " << result << "\n";
}