#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

fstream inf("bomboane.in");
ofstream outf("bomboane.out");

vector<int> v;
int a, b, t = 0; // a- bobo curenta ; b- cea anterioara; t - lungimea sirului; m - lung sir max
bool boo = false;

int main() {
    for(int i = 0; i < 30; i++) {
        b = a;
        inf >> a;
        if(a == 3) {
            boo = true;
        }
        if(a == b) {
            if(boo) {
                v.push_back(t);
            }
            t = 0;
            boo = false;
        }
        t++;
    }
    outf << *max_element(v.begin(), v.begin() + v.size());
    return 0;
}
