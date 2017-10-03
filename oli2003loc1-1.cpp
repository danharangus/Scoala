#include <fstream>
#include <cmath>

using namespace std;

ifstream inf("suma.in");
ofstream outf("suma.out");

int n, s;

int sumacifre(int x) {
    int s = 0;
    while(x > 0) {
        s += x%10;
        x /= 10;
    }
    return s;
}

int main() {
    inf >> n;
    for(int i = 1; i < n; i *= 10) {
        s += sumacifre(n) * i;
    }
    outf << s;
    return 0;
}
