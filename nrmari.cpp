#include <iostream>
#include <fstream>

using namespace std;

ifstream inf("nrmari.in");
ofstream outf("nrmari.out");

struct NrMare {
    string p10;
    string s;
    char operator[] (const int &x) {
        return s[x];
    }
    void operator= (const string x) {
        s = x;
    }
    bool operator/ (const int &x) {
        if(x == 2) {
            if(s[s.length()] % 2 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else if(x == 5) {
            if(s[s.length()] == 5 || s[s.length()] == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            cout << "ERROR" << endl;
            return false;
        }
    }
};

int to_int(string s) {
    int rez = 0;
    if(s.length() == 1) {
        rez = s[0] - 48;
    }
    if(s.length() == 2) {
        rez = (s[0] - 48) * 10 + (s[1] - 48);
    }
    return rez;
}

string operator/ (string &s, const int &x) {
    string rez;
    if(x == 2) {
        while(s.length() > 0) {
            string current = "";
            if(s[0] < '2') {
                current += s[0];
                current += s[1];
                int p = to_int(current);
                if(p % 2 != 0) {
                    s.erase(s.begin(), s.begin() + 1);
                    s.insert(s.begin(), '1');
                }
                else {
                    s.erase(s.begin(), s.begin() + 1);
                }
                p /= 2;
                rez += (char) (p + 48);
            }
            else {
                current += s[0];
                int p = to_int(current);
                if(p % 2 != 0) {
                    s[0] = '1';
                }
                else {
                    s.erase(s.begin());
                }
                p /= 2;
                rez += (char) (p + 48);
            }
        }
    }
}

void operator<< (ostream &o, NrMare &x) {
    o << x.s;
}

int n1, n2;

int main() {
    NrMare a;
    inf >> n1 >> n2;
    char c;
    for(short i = 0; i < n1; i++) {
        inf >> c;
        a.s += c;
    }
    for(short i = 0; i < n2; i++) {
        inf >> c;
        a.s += c;
    }
    while(a[0] == '0') {
        a.s.erase(a.s.begin());
    }
    while(a[a.s.length() - 1] == '0') {
        a.s.erase(a.s.begin() + a.s.length() - 1);
    }
    short sum = n1 + n2;
    a.p10 = "1";
    for(short i = 0; i < sum; i++) {
        a.p10 += '0';
    }
    string s = "320";
    cout << s / 2;
    return 0;
}
