#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream inf("roata.in");
ofstream outf("roata.out");

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return (a.first < b.first);
}

vector< pair<int, int> > v;

int main() {
    int n, p;
    inf >> n >> p;
    long long s = 0, s2 = 0;
    int t;
    for(int i = 0; i < n && i < p; i++) {
        inf >> t;
        s += t;
        v.push_back(make_pair(t, i));
    }
    outf << "                       " << endl; /// spatiu gol pt suma
    int c = n;
    int sterse = 0, rez = 0;
    while(sterse != v.size()) {
        sterse = 0;
        int minim = 200000, maxim = 0, maxpoz;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first < minim && v[i].first) {
                minim = v[i].first;
            }
            if(v[i].first >= maxim) {
                maxim = v[i].first;
                maxpoz = i + 1;
            }
        }
        s2 += minim;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first == 0) {
                sterse++;
                continue;
            }
            v[i].first -= minim;
            if(v[i].first == 0) {
                outf << v[i].second + 1 << " ";
                if(inf >> t) {
                    s += t;
                    v[i].first = t;
                    v[i].second = c;
                    c++;
                }
            }
        }
        if(sterse < v.size()) {
            rez = maxpoz;
        }
    }
    outf << endl << rez;
    outf.seekp(0, ios_base::beg);
    outf << s;
    return 0;
}
