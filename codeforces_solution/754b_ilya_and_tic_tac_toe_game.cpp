#include <bits/stdc++.h>

using namespace std;

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

ll n = 4;
char arr[5][5];

bool check() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 3; j <= n; ++j) {
            if(arr[i][j] == 'x' && arr[i][j - 1] == 'x' && arr[i][j - 2] == 'x') {
                return true;
            }
        }
    }
    for(int i = 3; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(arr[i][j] == 'x' && arr[i - 1][j] == 'x' && arr[i - 2][j] == 'x')
                return true;
        }
    }
    for(int i = 3; i <= n; ++i) {
        for(int j = 3; j <= n; ++j) {
            if(arr[i][j] == 'x' && arr[i - 1][j  - 1] == 'x' && arr[i - 2][j - 2] == 'x')
                return true;
        }
    }

    for(int i = 3; i <= n; ++i) {
        for(int j = 1; j <= 2; ++j) {
            if(arr[i][j] == 'x' && arr[i - 1][j + 1] == 'x' && arr[i - 2][j + 2] == 'x')
                return true;
        }
    }
    return false;
}

void solve() {
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 4; ++j) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 4; ++j) {
            if(arr[i][j] == '.') {
                arr[i][j] = 'x';
                if(check()) {
                    cout << "YES" << endl;
                    return;
                }
                arr[i][j] = '.';
            }
        }
    }
    cout << "NO" << endl;
}    

int main() {
    double start = clock();
    int tc = 1;
    //cin >> tc;
    while(tc--) {
       solve();
    }
    cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
    return 0;
}
