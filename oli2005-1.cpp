#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream inf("numar.in");
ofstream outf("numar.out");

int n, x, siruri = 0;
vector<int> v;
int tocheck[50][2];


void maxdig(int a, int &m) {
    do {
        int t = a % 10;
        if(t > m) {
            m = t;
        }
        a /= 10;
    } while(a > 0);
    return;
}

int foo() { // ne dam seama ce vrem sa prelucram
    int t = 0; // dim sirului - 1
    int temp; // poz de inceput a sirului
    for(int i = 0; i+1 < v.size(); i++) {
        while(v[i] < v[i+1]) {
            if(t == 0) {
                temp = i;
            }
            t++;
            i++;
        }
        if(t) {
            tocheck[siruri][0] = t+1;
            tocheck[siruri][1] = temp - tocheck[siruri-1][0];
            siruri++;
        }
        t = 0;
        temp = 0;
    }
    if(siruri) {
        return 1;
    }
    return 0;
}

void fun() {
    for(int i = 0; i < siruri; i++) {
        int m = 0;
        int s = tocheck[siruri][0];
        int x = tocheck[siruri][1];
        for(int i = 0; i < s; i++) {
            maxdig(v[x], m);
            v.erase(v.begin() + x);
        } //Problema: m nu se schimba deloc?
        v.insert(v.begin() + x, m);
        cout << m;
        cin.ignore();
    }
    siruri = 0;
    return;
}

int main() {
    inf >> n;
    for(int i = 0; i < n; i++) {
        int t;
        inf >> t;
        v.push_back(t);
    }
    foo(); // pana aici e bine ;)
    for(int i = 0; i < siruri; i++) {
        cout << tocheck[i][0] << "  " << tocheck[i][1];
        cin.ignore();
    }
    fun();
   /* while(foo()) {
        fun();
    } */
    return 0;
}
