#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

ifstream inf("oli2013time.in");
ofstream outf("oli2013time.out");

int pcf(int x) {
    int t;
    do {
        t = x % 10;
        x /= 10;
    } while(x > 0);
    return t;
}

struct Account {
    unsigned short ID, sum;
};

bool compare(Account acc1, Account acc2) {
    return acc1.sum < acc2.sum;
}

int n, s;
vector<Account> v;
vector< vector<unsigned short> > ap;

int main() {
    inf >> n;
    for(int i = 0; i < n; i++) {
        Account temp;
        inf >> temp.ID;
        inf >> temp.sum;
        if(temp.sum % n == 0) {
            outf << temp.ID;
            return 0;
        }
        if(pcf(temp.ID) == temp.ID % 10) {
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++) {
        unsigned short s = 0;
        vector<unsigned short> id;
        for(int k = 0; k <= i; k++) {
            s += v[k].sum;
            id.push_back(v[k].ID);
        }
        s %= n;
        for(int k = 0; k < ap.size() || s == 0; k++) {
            if(s == 0) {
                for(int j = 0; j < id.size(); j++) {
                    outf << id[j] << " ";
                }
                return 0;
            }
            if(s == ap[k][0]) {
                for(int j = k+1; j < id.size(); j++) {
                    outf << id[j] << " ";
                }
                return 0;
            }
        }
        id.insert(id.begin(), s);
        ap.push_back(id);
    }
    return 0;
}
