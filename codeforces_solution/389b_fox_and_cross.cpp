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

// infinite grids
#define N 105
char arr[N][N];

bool can(int x, int y) {
    if(arr[x][y] != '#')
        return false;
    if(arr[x - 1][y] != '#')
        return false;
    if(arr[x + 1][y] != '#')
        return false;
    if(arr[x][y - 1] != '#')
        return false;
    if(arr[x][y + 1] != '#')
        return false;
    return true;
}

void clear(int x, int y) {
    arr[x][y] = '.';
    arr[x + 1][y] = '.';
    arr[x - 1][y] = '.';
    arr[x][y + 1] = '.';
    arr[x][y - 1] = '.';
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) { 
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) { 
            if(can(i, j)) {
                clear(i, j);
            }
        }
    }

     for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) { 
            if(arr[i][j] == '#') { 
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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