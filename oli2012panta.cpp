#include <iostream>
#include <fstream>

using namespace std;

ifstream inf("panta.in");

int n, m;

bool panta1(int x) {
    do {
        if(x % 10 <= (x / 10) % 10) {
            return false;
        }
        x /= 10;
    } while(x > 10);
    return true;
}

bool panta2(int x) {
    do {
        if(x % 10 >= (x / 10) % 10) {
            return false;
        }
        x /= 10;
    } while(x > 10);
    return true;
}

int main() {
    inf >> n;
    int t = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        inf >> temp;
        if(panta1(temp) || panta2(temp)) {
            t++;
            if(temp > m) {
                m = temp;
            }
        }
    }
    cout << t << endl << m;
    return 0;
}
