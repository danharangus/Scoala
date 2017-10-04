#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int x = (n + 2) / 2;
    for(int b = 1; b < x; b++) {
        for(int a = b+1; a < n;a++) {
            if((a+b) * (a-b+1) / 2 > n) {
                break;
            }
            if((a+b) * (a-b+1) / 2 == n) {
                for(int i = b; i <= a; i++) {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
