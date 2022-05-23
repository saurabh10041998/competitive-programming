#include <bits/stdc++.h>

using namespace std;

#define LOCAL true

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define endl "\n"

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n;
    cin >> n;
    vector<int>even, odd;
    int x;
    for(int i = 0;  i < 2 * n; ++i) {
        cin >> x;
        if(x & 1)
            odd.push_back(i + 1);
        else
            even.push_back(i + 1);
    }
    dbg(odd);
    dbg(even);
    int x1 = even.size();
    int x2 = odd.size();
    if(x1 % 2 == 0 &&  x2 % 2 == 0) {
        if(x1 > 2) {
            for(int i = 2; i < x1 - 1; i += 2) {
                cout <<  even[i] << " " << even[i + 1] << endl;
            }
            for(int i = 0; i < x2 - 1; i += 2){
                cout << odd[i] << " " << odd[i + 1] << endl;
            }
        }else {
            for(int i = 2; i < x2 - 1; i += 2) {
                cout << odd[i] << " " << odd[i + 1] << endl;
            }
            for(int i = 0; i < x1 - 1; i += 2) {
                cout << even[i] << " " << even[i + 1] << endl;
            }
        } 
    }else {
        // only two cases possible
        for(int i = 1; i < x1 - 1; i += 2)
            cout << even[i] << " " << even[i + 1] << endl;
        for(int i = 1; i < x2 - 1; i += 2)
            cout << odd[i] << " " << odd[i + 1] << endl;
    }
}

int main() {
    double start = clock();
    int tc = 1;
    cin >> tc;
    while(tc--) {
       solve();
    }
    cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
    return 0;
}
