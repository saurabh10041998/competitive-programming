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
    ll n;
    cin >> n; 
    string str;
    cin >> str; 
    vector<ll>arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    ll k = 0;
    vector<bool>visited(n, false);
    int  flag = 0x0; 
    while(1) { 
        if(str[k] == '>')
            k += arr[k];
        else
            k -= arr[k];
        if(k > n - 1 || k < 0) {
            flag = 0xdf;
            break;
        }
        if(visited[k]) {
            flag = 0xff;
            break;
        }
        visited[k] = true;
    }
    if(flag == 0xdf)
        cout << "FINITE" << endl;
    else if (flag == 0xff)
        cout << "INFINITE" << endl;
    else
        return;
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
