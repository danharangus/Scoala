#include <iostream>
#include <cmath>

using namespace std;

int a, b;

bool doidoi(int x) {
    int t = 0;
    do {
        if(x % 2 == 1) {
            t++;
        }
        if(t == 3) {
            return false;
        }
        x /= 2;
    } while(x > 0);
    if(t == 2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cin >> a >> b;
    int t2 = 0;
    int t1 = (int) sqrt(b) - (int) sqrt(a);
    for(int i = a + (a % 2); i <= b; i += 2) {
        if(doidoi(i)) {
            t2++;
        }
    }
    cout << t1 << endl << t2;
    return 0;
}
