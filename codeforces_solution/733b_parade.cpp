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
    vector<pair<int, int>>arr(n);
    int left_sum = 0;
    int right_sum = 0;
    for(int i = 0; i < n; ++i) { 
        cin >> arr[i].first >> arr[i].second; 
        left_sum += arr[i].first;
        right_sum += arr[i].second;
    }
    int max_beauty = std::abs(left_sum - right_sum);
    int index = -1;
    int cur_beauty = 0;
    for(int i = 0; i < n; ++i) { 
        int new_left_sum = left_sum - arr[i].first + arr[i].second;
        int new_right_sum = right_sum - arr[i].second + arr[i].first;
        cur_beauty = std::abs(new_left_sum - new_right_sum);
        if(cur_beauty > max_beauty) { 
            max_beauty = cur_beauty;
            index = i;
        }
    }
    cout << index + 1 << endl;
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
