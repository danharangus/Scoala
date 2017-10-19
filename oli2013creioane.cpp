#include <iostream>
#include <fstream>

using namespace std;

ifstream inf("creioane.in");

int n, m, mgalbene, mgalbenelen;
int arr[4] = {0, 0, 0, 0};

int main() {
    inf >> n;
    int a, b;
    inf >> a;
    arr[a-1]++;
    cout << a << " ";
    for(int i = 0; i < n; i++) {
        inf >> b;
        if(a != b) {
            a = b;
            arr[b]++;
            arr[0]++;
            cout << b << " ";
        }
        else {
            if(arr[3] > 0 && arr[0] > m) {
                m = arr[0];
            }
            if(arr[3] > mgalbene) {
                mgalbene = arr[3];
                mgalbenelen = arr[0];
            }
            arr[0] = 1;
            arr[1] = 0;
            arr[2] = 0;
            arr[3] = 0;
            arr[b]++;
            cout << endl << b << " ";
        }
    }
    cout << endl << m << endl << mgalbenelen;
    return 0;
}
