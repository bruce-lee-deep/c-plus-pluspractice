#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x; 
    if (!(cin >> x)) return 0;
    long long x_floor = floor(x);
    if (x_floor % 2 == 0) {
        cout << fixed << setprecision(2) << x - (double)x_floor << endl;
    }
    else {
        cout << fixed << setprecision(2) << (double)x_floor + 1.0 - x << endl;
    }
    return 0;
}
