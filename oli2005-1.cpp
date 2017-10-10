#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream inf("numar.in");
ofstream outf("numar.out");

int n, t, ln = 0, lnmax = 0, startcheck = 0, a;
vector<int> v;
vector<int> cifremax;

void foo(int x, int y) {
    int m = 0;
    for(int i = x+1; i <= y; i++) {
        if(cifremax[i] > m) {
            m = cifremax[i];
        }
        v.erase(v.begin() + x);
        cifremax.erase(cifremax.begin() + x);
    }
    v[x] = m;
    cifremax[x] = m;
    return;
}

int bar() {
    ln = 0;
    for(int i = 1; i < v.size(); i++) {
        if(v[i-1] < v[i]) {
            ln++;
            a++;
        }
        else {
            if(ln > lnmax) {
                lnmax = ln;
                startcheck = i - ln - 1;
            }
            ln = 0;
        }
    }
    if(a == 0) {
        return 0;
    }
    foo(startcheck, startcheck + ln);
    lnmax = 0;
    a = 0;
    return 1;
}

int main() {
    inf >> n;
    for(int i = 0; i < n; i++) {
        inf >> t;
        v.push_back(t);
        int m = 0;
        do{
            int x  = t % 10;
            if(x > m) {
                m = x;
            }
            t /= 10;
        } while(t > 0);
        cifremax.push_back(m);
    }
    while(bar()) {}
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << *max_element(v.begin(), v.begin() + v.size()) << " " << *min_element(v.begin(), v.begin() + v.size());
    return 0;
}

