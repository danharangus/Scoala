#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void prime(int x) {
    vector<bool> v;
    for(int i = 0; i < x; i++) {
        v.push_back(0);
    }
    int lim = sqrt(x);
    int i = 2;
    cout << "2 ";
    while(i <= lim) {
        v[i] = 1;
        for(int k = i * i; k <= x; k += i) {
            v[k] = 1;
        }
        for(int k = i; k <= lim; k++) {
            if(v[k] == false) {
                i = k;
                cout << i << " ";
                break;
            }
            if(k == lim || k == lim - 1) {
                i = lim+1;
            }
        }
    }
    for(int k = i; k < x; k++) {
        if(!v[k]) {
            cout << k << " ";
        }
    }
    return;
}

int main() {
    prime(13455);
}
