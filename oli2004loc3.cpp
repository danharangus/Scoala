#include <fstream>

using namespace std;

fstream inf("bomboane.in");
ofstream outf("bomboane.out");

int a, b, t, m = 1;

int main() {
    for(int i = 0; i < 30; i++) {
        b = a;
        inf >> a;
        if(t > m) {
            m = t;
        }
        t++;
        if(a == b) {
            t = 0;
        }
    }
    outf << m;
    return 0;
}
