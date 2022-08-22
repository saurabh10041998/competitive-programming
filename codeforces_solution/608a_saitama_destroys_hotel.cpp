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
    int n, s;
    cin >> n >> s; 
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    std::sort(arr.begin(), arr.end(), greater<pair<int,int>>());
    dbg(arr);
    int current_floor = s;
    int total_time = 0;
    //int arrival_time;
    for(int i = 0; i < n; ++i) {
        total_time += current_floor - arr[i].first;
        int waiting_time = std::max(arr[i].second - total_time, 0);
        total_time += waiting_time;
        current_floor = arr[i].first;
    }
    total_time += current_floor;
    cout << total_time << endl;
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
