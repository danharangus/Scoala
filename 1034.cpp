#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

ifstream inf("roata.in");
ofstream outf("roata.out");

priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;

int main() {
    int n, p;
    inf >> n >> p;
    int t;
    long long s = 0;
    for(int i = 0; i < n && i < p; i++) {
        inf >> t;
        s += t;
        q.push(make_pair(t, i));
    }
    outf << "                   \n";
    int c = n;
    while(!q.empty()) {
        int minim = q.top().first;
        outf << q.top().second + 1 << " ";
        q.pop();
        if(inf >> t) {
            q.push(make_pair(t + minim, c));
            c++;
        }
    }
    outf.seekp(0, ios_base::beg);
    outf << s;
    outf.seekp(0, ios_base::end);
    return 0;
}
