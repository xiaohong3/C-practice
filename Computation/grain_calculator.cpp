#include "../std_lib_facilities.h"

int power(int base, int p) {
    if (p > 0) {
        return base * power(base, p - 1);
    } else {
        return 1;
    }
}

int getNumOfSquares(int numOfGrains) {
    int numOfSquares = 0;
    int currentTotalGrains = 0;
    
    while(currentTotalGrains < numOfGrains) {
        currentTotalGrains += power(2, numOfSquares);
        ++numOfSquares;
        cout << "Num of squares: " << numOfSquares;
        cout << "\n";

        cout << "Num of grains: " << currentTotalGrains;
        cout << "\n";
    }
    return numOfSquares;
}

int getTotalNumOfGrains(int squares) {
    int total = 0;
    for(int i = 1; i <= squares; ++i) {
        total += power(2, (i - 1));
        cout << "Total now: " << total;
        cout << "\n";
    }
    cout << "Total grains for squares are: " << total;
    cout << "\n";
    return total;
}

int main() {
    // getNumOfSquares(1000000000);
    getTotalNumOfGrains(64);
    return 0;
}