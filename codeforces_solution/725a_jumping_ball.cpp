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
    int n;
    cin >> n;
    string str; 
    cin >> str; 
    vector<int>sign(n);
    int cnt = (str[0] == '<' ? 1 : 0);
    sign[0] = (str[0] == '<' ? -1 : 1);
    for(int i = 1; i < n; ++i) {
        if(str[i] == '<') {
            if(sign[i - 1] < 0) {
                sign[i] = sign[i - 1] - 1;
            }else {
                sign[i] = -1;
            }
        }else { 
            if(sign[i - 1] > 0) {
                sign[i] = sign[i - 1] + 1;
            }else { 
                sign[i] = 1;
            }
        }
        if(sign[i] < 0 && std::abs(sign[i]) == i + 1) {
            cnt++; 
        }
    }
    if(sign[n - 1] > 0 && sign[n - sign[n - 1]] == 1) {
        cnt += sign[n - 1];
    }
    cout << cnt << endl;
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
