#include "../../std_lib_facilities.h"
#include "./Calculator.h"

int main() {
    try {
        Calculator c;
        c.expression();
        // while(cin) {
        //     cout << c.expression() << '\n';
        // }
        keep_window_open("~0");
    } catch(exception& e) {
        cerr << e.what() << endl;
        keep_window_open ("~1");
        return 1;
    } catch (...) {
        cerr << "exception \n";
        keep_window_open ("~2");
        return 2;
    }

    return 0;
}