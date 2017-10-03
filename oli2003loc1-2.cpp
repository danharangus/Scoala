#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream inf("numere.in");
ofstream outf("numere.out");

int n, x;

// sirul este de forma 2^x-1 + 1, 2^x-1 + 2, ..., 2^x-1 + 2^x-2 pentru fiecare x mai mic decat n la care se adauga
// sirul 1, 2 si
// sirul de forma 2^x - 2^x-2, 2^x - (2^x-2 - 1), ... , 2^x

int main() {
    cin >> n;
    for(int i = n; i > 1; i--) {
        int p1 = pow(2, i-1);
        int p2 = pow(2, i-2);
        for(int k = 1; k <= p2; k++) {
            cout << p1 + k << " ";
        }
    }
    cout << "1 2 ";
    for(int i = 2; i <= n; i++) {
        int p2 = pow(2, i-2);
        int p1 = pow(2, i);
        for(int k = p2; k >= 0; k--) {
            cout << p1 - k << " ";
        }
    }
    return 0;
}
