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
    vector<ll>mis;
    vector<bool>arr(n + 1);
    for(ll i = 0; i < n; ++i) {
        if(str[i] == '0'){
            mis.push_back(i + 1);
            arr[i + 1] = true;
        }
    }
    ll cost = 0;
    for(ll i = 0; i < (ll)mis.size(); ++i) {
        if(str[mis[i] - 1] == '0') {
            if(arr[mis[i]] == true) {
                cost += mis[i];
                arr[mis[i]] = false;
            }
            for(int j = 2 * mis[i]; j <= n; j += mis[i]) { 
                if(str[j - 1] == '1') {
                    break;
                }else {
                    if(arr[j] == true)
                        cost += mis[i];
                    arr[j] = false;
                }
            }
        }else {
            for(int j = 2 * mis[i]; j <= n; j += mis[i]) { 
                if(str[j - 1] == '1') {
                    break;
                }else {
                    if(arr[j] == true)
                        cost += mis[i];
                    arr[j] = false;
                }
            }
        }
    }
    cout << cost << endl;
}    

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double start = clock();
    int tc = 1;
    cin >> tc;
    while(tc--) {
       solve();
    }
    cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
    return 0;
}
