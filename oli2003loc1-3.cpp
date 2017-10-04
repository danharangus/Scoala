#include <fstream>

using namespace std;

ifstream inf("gauri.in");
ofstream outf("gauri.out");

string x[100];
int m, n, t = 0, s, ma = 0;

int gaura(int a, int b, int& t) {
    x[a][b] = '*';
    t++;
    if(x[a+1][b] == '0') { //jos
        gaura(a+1, b, t);
    }
    if(a > 0&& x[a-1][b] == '0') { //sus
        gaura(a-1, b, t);
    }
    if(x[a][b+1] == '0') { //dreapta
        gaura(a, b+1, t);
    }
    if(b>0 && x[a][b-1] == '0') { //stanga
        gaura(a, b-1, t);
    }
    return t;
}

int main() {
    inf >> m >> n;
    for(int i = 0; i < m; i++) {
        inf >> x[i];
    }
    for(int i = 0; i < n; i++) {
        if(x[0][i] == '0') {
            gaura(0, i, s);
        }
        if(x[m-1][i] == '0') {
            gaura(m-1, i, s);
        }
    }
    for(int i = 0; i < m; i++) {
        if(x[i][0] == '0') {
            gaura(i, 0, s);
        }
        if(x[i][n-1] == '0') {
            gaura(i, n-1, s);
        }
    }
    for(int a = 1; a < n-1; a++) {
        for(int b = 1; b < m-1; b++) {
            if(x[a][b] == '0') {
                t = 0;
                if(gaura(a, b, t) > ma) {
                    ma = t;
                }
            }
        }
    }
    for(int a = 0; a < n; a++) {
        outf << x[a] << endl;
    }
    outf << ma;
    return 0;
}
