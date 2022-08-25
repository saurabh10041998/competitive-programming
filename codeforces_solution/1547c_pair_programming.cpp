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
    int k, n, m;
    cin >> k >> n >> m;
    vector<int>arr(n);
    for(int i =  0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int>brr(m);
    for(int i = 0; i < m; ++i) {
        cin >> brr[i];
    }
    int i = 0;
    int j = 0;
    bool ok = true;
    int current = 0;
    vector<int>ans;
    while(i < n && j < m) {
        if(arr[i] == 0) {
            ans.push_back(arr[i]);
            i++;
            k++;
            continue;
        }else if(brr[j] == 0) {
            ans.push_back(brr[j]);
            j++;
            k++;
            continue;
        }
        if(arr[i] < brr[j]) {
            current = arr[i];
            i++;
        }else {
            current = brr[j];
            j++;
        }
        if(current <= k) {
            ans.push_back(current);
        }else {
            ok = false;
            break;
        }
    }
    if(ok) {
        for(; i < n; ++i) {
            if(arr[i] == 0) {
                ans.push_back(arr[i]);
                k++;
            }else if(arr[i] <= k) {
                ans.push_back(arr[i]);
            }else {
                ok = false;
                break;
            }
        }
        for(;j < m; ++j) {
            if(brr[j] == 0) {
                ans.push_back(brr[j]);
                k++;
            }else if(brr[j] <= k) {
                ans.push_back(brr[j]);
            }else {
                ok = false;
                break;
            }
        }
    }
    if(!ok) { 
        cout << -1 << endl;
    }else {
        for(auto x: ans)
            cout << x << " ";
        cout << endl;
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
