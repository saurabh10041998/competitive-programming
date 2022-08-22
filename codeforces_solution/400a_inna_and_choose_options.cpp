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
    string str;
    cin >> str;
    vector<bool>flag(6, false);
    int ans = 0;
    for(int i = 0; i < 12; ++i){
        if(str[i] == 'X') {
            flag[0] = true;
            ans++;
            break;
        }
    }
    for(int i = 0; i < 6; ++i) {
        if(str[i] == 'X' && str[i + 6] == 'X') {
            flag[1] = true;
            ans++;
            break;
        }
    }
    for(int i = 0; i < 4; ++i) { 
        if(str[i] == 'X' && str[i + 4] == 'X' && str[i + 8] == 'X') {
            flag[2] = true;
            ans++;
            break;
        }
    }
    for(int i = 0; i < 3; ++i) {
        if(str[i] == 'X' && str[i + 3] == 'X' && str[i + 6] == 'X' && str[i + 9] == 'X') { 
            flag[3] = true;
            ans++;
            break;
        }
    }
    for(int i = 0; i < 2; ++i) {
        if(str[i] == 'X' && str[i + 2] == 'X' && str[i + 4] == 'X' && str[i + 6] == 'X' && str[i + 8] == 'X' && str[i + 10] == 'X') {
            flag[4] = true;
            ans++;
            break;
        }
    }
    ans++;
    flag[5] = true;
    for(int i = 0; i < 12; ++i) {
        if(str[i] == 'O') {
            --ans;
            flag[5] = false;
            break;
        }
    }

    cout << ans << " ";
    if(flag[0])
        cout << "1x12" << " ";
    if(flag[1])
        cout << "2x6" << " ";
    if(flag[2])
        cout << "3x4" << " ";
    if(flag[3])
        cout << "4x3" << " ";
    if(flag[4])
        cout << "6x2" << " ";
    if(flag[5])
        cout << "12x1" << " ";
    cout << endl;
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
