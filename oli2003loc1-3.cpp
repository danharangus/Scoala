#include <fstream>

using namespace std;

ifstream inf("gauri.in");
ofstream outf("gauri.out");

string x[100];
int m, n, t;

int gaura(int a, int b, int* t) {
    if(x[a][b] == 0) {
        *t++;
        if(x[a+1][b] == '0') { //jos
            gaura(a+1, b, t);
        }
        if(x[a-1][b] == '0') { //sus
            gaura(a-1, b, t);
        }
        if(x[a][b+1] == '0') { //dreapta
            gaura(a, b+1, t);
        }
        if(x[a][b-1] == '0') { //stanga
            gaura(a, b-1, t);
        }
    }
    return *t;
} // Ce se intampla???????

int main() {
    inf >> m >> n;
    for(int i = 0; i < m; i++) {
        inf >> x[i];
    }
    for(int a = 1; a < n-1; a++) {
        for(int b = 1; b < m-1; b++) {
            outf << gaura(a, b, 0);
        }
    }
    return 0;
}
