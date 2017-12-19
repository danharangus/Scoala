#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int x, k, xcpy, cf, xant, xpos, p;
    long long rez = 0;
    cin >> x >> k;
    if(k == 0) {
        goto Solver0;
    }
    xcpy = x;
    cf = x % 10;
    x /= 10;
    xant = x;
    rez += xant + (cf > k);
    p = 1;
    xpos = 0;
    while(x > 9) {
        cf = x % 10;
        p *= 10;
        xant -= xant % p;
        xpos = xcpy % p;
        rez += xant;
        if(cf == k) {
            rez += xpos;
        }
        else if(cf > k) {
            rez += p;
        }
        x /= 10;
    }
    cf = x % 10;
    p *= 10;
    if(cf == k) {
        rez += xcpy % p;
    }
    else if(cf > k) {
        rez += p;
    }
    Solver0:
    cout << "rezulat: " << rez;
    return 0;
}
