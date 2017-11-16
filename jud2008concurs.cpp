#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;

ifstream inf("concurs.in");
ofstream outf("concurs.out");

vector< vector<short> > v;

int main() {
    short n;
    inf >> n;
    for(short i = 0; i < n; i++) {
        short a, b;
        inf >> a >> b;
        bool boo = false;
        for(short k = 0; k < v.size(); k++) {
            if(v[k][0] == a) {
                v[k].push_back(b);
                boo = true;
            }
        }
        if(!boo) {
            vector<short> temp;
            temp.push_back(a);
            temp.push_back(b);
            v.push_back(temp);
        }
    }
    for(short i = 0; i < v.size(); i++) {
        sort(v[i].begin() + 1, v[i].end());
    }
    for(short i = 0; i < v.size(); i++) {
        short t = 0;
        for(short k = 1; k < v[i].size(); k++) {
            outf << v[i][0] << " " << v[i][k] << endl;
            if(v[i + 1].size() < 2) {
                v.erase(v.begin() + i + 1);
            }
            if(v[i + 1].size() > 1) {
                outf << v[i + 1][0] << " " << v[i + 1][1] << endl;
                v[i + 1].erase(v[i + 1].begin() + 1);
            }
            t++;
        }
    }
    return 0;
}
