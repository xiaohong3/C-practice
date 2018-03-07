#include "../std_lib_facilities.h"

bool isLegalUnit(string unit) {
    if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft") {
        return true;
    } else {
        return false;
    }
}

double convertToMeter(string unit, double x) {
    if (unit == "m") {
        return x;
    } else if (unit == "cm") {
        return x / 100;
    } else if (unit == "in") {
        return x / 39.37;
    } else if (unit == "ft") {
        return x / 3.28;
    } else {
        simple_error("Invalid unit");
    }
}

int main() {
    double x;
    double biggest = -INFINITY;
    double smallest = INFINITY;
    double sum = 0;
    int count = 0;
    string unit;
    vector<double> list;

    while(cin >> x >> unit) {
        if (!isLegalUnit(unit)) {
            cout << "Please enter a legal unit (cm, m, in,ft)";
            cout << "\n";
            continue;
        }

        cout << "the number entered: " << x;
        cout << "\n";

        sum += convertToMeter(unit, x);
        list.push_back(convertToMeter(unit, x));
        ++count;

        if (x > biggest) {
            biggest = x;
            cout << "the biggest so far entered: " << biggest;
            cout << "\n";
        }

        if (x < smallest) {
            smallest = x;
            cout << "the smallest so far entered: " << smallest;
            cout << "\n";
        }
    }

    cout << "Sum in meter is: " << sum;
    cout << "\n";

    cout << "The number of values is: " << count;
    cout << "\n";

    cout << "The biggest value is: " << biggest;
    cout << "\n";

    cout << "The smallest value is: " << smallest;
    cout << "\n";

    for (double m : list) {
        cout << m << "\n";
    }

    sort(list.begin(), list.end());

    for (double m : list) {
        cout << m << "\n";
    }
    return 0;
}