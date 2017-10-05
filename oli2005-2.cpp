#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream inf("date.in");
ofstream outf("date.out");

int n, a, b, c, numa;
long long p;

void foo(long long r) {
    long long x = r * r;
    int k = (log10(x) + 1) / 2;
    double po = pow(10, k);
    int d = po;
    a = (x / (d * 10)) % 10;
    while(a == 0) {
        d *= 10;
        a = (x / (d * 100)) % 10;
    }
    b = (x / d) % 10;
    c = (x / (d / 10)) % 10;
    cout << c;
    return;
    numa = a * 100 + b * 10 + c;
    outf << numa;
    return;
}

int main() {
    inf >> n;
    inf >> p;
    foo(p);
    for(int i = 1; i < n; i++) {
        foo(numa);
    }
    return 0;
}
