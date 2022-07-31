#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
            double A; cin >> A;
            double B; cin >> B;
            double C; cin >> C;
    
            cout << hex << showbase << setw(0) << nouppercase;
            cout << (long long) A << endl;
            cout << dec << setw(0xf)<< right << setprecision(2) << fixed << showpos << setfill('_');
            cout << B << endl;
            cout << dec << setw(0) << setprecision(9) << scientific << noshowpos << uppercase;
            cout << C << endl;
        }
    return 0;

}
