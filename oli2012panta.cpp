#include <iostream>
#include <fstream>

using namespace std;

ifstream inf("panta.in");

int n;
string m;

bool panta(string x) {
    for(int i = 0; i < x.length(); i++) {
        if(x[i] < x[i+1]) {
            return false;
        }
    }
    return true;
}

bool panta(string x, bool b) {
    for(int i = 0; i < x.length(); i++) {
        if(x[i] > x[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    inf >> n;
    int t = 0;
    for(int i = 0; i < n; i++) {
        string temp;
        inf >> temp;
        if(panta(temp) || panta(temp, true)) {
            t++;
            if(temp > m) {
                m = temp;
            }
        }
    }
    cout << t << endl << m;
    return 0;
}
