#include <fstream>
#include <iostream>
#include <vector>
#include <thread>
#include <iomanip>
#include <mutex>

using namespace std;

ifstream inf("cri.in");
ofstream outf("cri.out");

vector< vector<int> > v;
mutex m;
int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
int lin, col, x, y;

void maxsum(const int& startx, const int& starty, const int& endx, const int& endy, int& s) {
    int minim = 2000000;
    if((endx - startx) % 2 || (endy - starty) % 2) {
        for(int i = startx; i < endx; i++) {
            for(int j = starty; j < endy; j++) {
                s += v[i][j];
            }
        }
        return;
    }
    for(int i = startx; i < endx; i++) {
        for(int j = starty; j < endy; j++) {
            s += v[i][j];
            if(v[i][j] < minim) {
                minim = v[i][j];
            }
        }
    }
    s -= minim;
}

int main() {
    inf >> lin >> col >> x >> y;
    int x2 = x - 1; ///
    int y2 = y - 1; /// pentru referinte
    v.resize(lin);
    for(int i = 0; i < lin; i++) {
        v[i].resize(col);
        for(int j = 0; j < col; j++) {
            inf >> v[i][j];
        }
    }
    thread t1(maxsum, 0, ref(x), 0, ref(y), ref(s1));
    thread t2(maxsum, 0, ref(x), ref(y2), ref(col), ref(s2));
    thread t3(maxsum, ref(x2), ref(lin), ref(y2), ref(col), ref(s3));
    thread t4(maxsum, ref(x2), ref(lin), 0, ref(y), ref(s4));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    outf << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
    ///*******************************************************************///
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            outf << setw(3) << v[i][j];
        }
        outf << endl;
    }
    outf << endl;
    return 0;
}
