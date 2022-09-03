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


void solve() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    vector<string>arr(k);
    for(int i = 0; i < k; ++i)
        arr[i] = string(k, '.');
    int r1 = r % k;
    int c1 = c % k;
    
    r1 = (r1 == 0) ? k - 1: r1 - 1;
    c1 = (c1 == 0) ? k - 1: c1 - 1;
    
    arr[r1][c1] = 'X';
    vector<bool>rows(k, false);
    vector<bool>cols(k, false);
    rows[r1] = true;
    cols[c1] = true;
    for(int i = 0; i < k; ++i) {
        if(rows[i])
            continue;
        for(int j = 0; j < k; ++j) {
            if(cols[j])
                continue;
            else {
                cols[j] = true;
                arr[i][j] = 'X';
                rows[i] = true;
                break;
            }
        }
    }
    vector<string>brr(k);
    for(int i = 0; i < k; ++i) {
        brr[i] = "";
        for(int j = 0; j < n / k; ++j) {
            brr[i] += arr[i];
        }
    }
    for(int i = 0; i < n/k; ++i) {
        for(int j = 0; j < k; ++j) {
            cout << brr[j] << endl;
        }
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
