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
    vector<int>arr(10, 0);
    int x;
    for(int i = 0; i < n; ++i) { 
        cin >> x;
        arr[x % 10]++;
    }
    vector<int>v;
    for(int i = 0; i < 10; ++i) { 
        for(int j = 0; j < std::min(arr[i], 3); j++) {
            v.push_back(i);
        }
    }
    bool ok  = false;
    int m = v.size();
    for(int i  = 0; i < m; ++i) { 
        for(int j =  i + 1; j < m; ++j) {
            for(int k = j + 1;  k < m; ++k) {
                if((v[i] + v[j] + v[k]) % 10 == 3){
                    ok = true;
                    break;
                }
            }
            if(ok)
                break;
        }
        if(ok)
            break;
    }
    cout << (ok ? "YES" : "NO") << endl;
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
