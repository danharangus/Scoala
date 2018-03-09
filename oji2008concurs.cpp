#include <bits/stdc++.h>

using namespace std;

ifstream inf("concurs.in");
ofstream outf("concurs.out");

bool comp(vector<int>& a, vector<int>& b) {
    return (a.size() < b.size());
}

array< vector<int>, 51 > v;

struct compq {
    bool operator() (const vector<int>& a, const vector<int>& b) {
        return(a.size() < b.size());
    }
};

priority_queue< vector<int>, vector< vector<int> >, compq> q;

int main() {
    int n;
    inf >> n;
    int maxpoz, minpoz = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        inf >> a >> b;
        v[a].push_back(b);
    }
    outf << "      " << endl;
    int nrjud = 0;
    for(int i = 0; i < 52; i++) {
        if(v[i].size()) {
            outf << v[i].size() << " ";
            nrjud++;
        }
    }
    outf.seekp(0, ios_base::beg);
    outf << nrjud;
    outf.seekp(0, ios_base::end);
    outf << endl;
    for(int i = 1; i < 51; i++) {
        if(v[i].size()) {
            sort(v[i].begin(), v[i].end(), greater<int>());
            v[i].insert(v[i].begin(), i);
            q.push(v[i]);
        }
    }
    while(!q.empty()) {
        vector<int> v1(q.top());
        q.pop();
        outf << v1[0] << " " << v1[v1.size() - 1] << endl;
        v1.pop_back();
        if(!q.empty()) {
            vector<int> v2(q.top());
            q.pop();
            outf << v2[0] << " " << v2[v2.size() - 1] << endl;
            v2.pop_back();
            if(v2.size() > 1) {
                q.push(v2);
            }
        }
        if(v1.size() > 1) {
            q.push(v1);
        }
    }
    return 0;
}
