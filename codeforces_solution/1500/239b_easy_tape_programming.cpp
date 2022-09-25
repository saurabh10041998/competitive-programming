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

void _solve(string s) {
    int cp = 0, dp = 1;
    vector<int>arr(10, 0);
    while(cp >= 0 && cp < s.size()) {
        bool erase = false;
        if(s[cp] >= '0' && s[cp] <= '9') {
            arr[s[cp] - '0']++;
            s[cp]--;
            if(s[cp] < '0')
                erase = true;
        }else {
            if(s[cp] == '>')
                dp = 1;
            else
                dp = -1;
            if(cp + dp >= 0 && cp + dp < s.size() && (s[cp + dp] == '>' || s[cp + dp] == '<')){
                erase = true;
            }
        }
        if(erase) {
            s.erase(cp, 1);
            if(dp == -1)
                cp--;
        }else {
            cp += dp;
        }
    }
    for(int i = 0; i < 10; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void solve() {
    int n,q, l, r;
    cin >> n >> q;
    string str;
    cin >> str;
    for(int i = 0; i < q; ++i) { 
        cin >> l >> r;
        _solve(str.substr(l - 1, r - l + 1));
    }
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
