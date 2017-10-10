#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream inf("colier.in");
ofstream outf("colier.out");

int n, k, t = 0;
int arr[1000];
int ap[1000];

int main() {
    inf >> n >> k;
    int p = n - k;
    for(int i = p; i < n; i++) {
        inf >> arr[i];
    }
    for(int i = 0; i < p; i++) {
        inf >> arr[i];
    }
    fill(ap, ap + 1000, 1);
    for(int i = 1; arr[i]; i++) {
        if(arr[i-1] == arr[i]) {
            ap[t]++;
        }
        else {
            t++;
        }
    }
    cout << *max_element(ap, ap + 1000);
    return 0;
}
