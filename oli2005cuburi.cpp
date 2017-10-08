#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream inf("cuburi.in");
ofstream outf("cuburi.out");

int n;
vector<int> vd;
vector<int> vc;

int main() {
    inf >> n;
    for(int i = 0; i < n; i++) {
        int td, tc;
        inf >> td;
        if(find(vd.begin(), vd.begin() + vd.size(), td) == vd.end()) {
            vd.push_back(td);
        }
        inf >> tc;
        if(find(vc.begin(), vc.begin() + vc.size(), tc) == vc.end()) {
            vc.push_back(tc);
        }
    }
    if(vd.size() > vc.size()) {
        outf << "D " << vd.size();
    }
    else if(vd.size() == vc.size()) {
        outf << "DC " << vd.size();
    }
    else {
        outf << "C " << vc.size();
    }
    return 0;
}
