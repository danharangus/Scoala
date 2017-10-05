#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x, n, a, b, c, mi, ma, p, t = 0;
vector<int> v;

void foo(int p) {
    if(find(v.begin(), v.begin() + v.size(), p) == v.end()) {
        t++;
        for(int k = 0; k < v.size(); k++) {
            if(p < v[k]) {
                v.insert(v.begin() + k, p);
                return;
            }
        }
        v.push_back(p);
    }
}

int main() {
    cin >> x >> n >> a >> b >> c;
    n--;
    v.push_back(x);
    v.push_back(x * a);
    v.push_back(x * b);
    v.push_back(x * c);
    if(n < 4) {
        cout << v[n];
    }
    else {
        for(int i = 1; t < n; i++) { // Problema: nu se stie cat de multe numere adauga fiecare iterare si atunci trb sa iau numere in plus
            p = v[i] * a;
            foo(p);
            p = v[i] * b;
            foo(p);
            p = v[i] * c;
            foo(p);
        }
    }
    cout << v[n];
    return 0;
}
