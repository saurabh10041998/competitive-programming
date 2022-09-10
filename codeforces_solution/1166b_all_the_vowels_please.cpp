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
    int k; 
    cin >> k;
    int n = -1, m = -1; 
    for(int i = 5; i <= k; ++i) {
        if(k % i == 0) { 
            if(k / i >= 5) { 
                m = i; 
                n = k / i; 
                break;
            }
        }
    }
    if(n == -1 && m == -1){ 
        cout << "-1" << endl;
    }else { 
        vector<vector<char>>arr(n + 1, vector<char>(m + 1, 'z')); 
        arr[1][1] = 'a', arr[1][2] = 'e', arr[1][3] = 'i', arr[1][4] = 'o', arr[1][5] = 'u';
        arr[2][1] = 'e', arr[2][2] = 'i', arr[2][3] = 'o', arr[2][4] = 'u', arr[2][5] = 'a';
        arr[3][1] = 'i', arr[3][2] = 'o', arr[3][3] = 'u', arr[3][4] = 'a', arr[3][5] = 'e';
        arr[4][1] = 'o', arr[4][2] = 'u', arr[4][3] = 'a', arr[4][4] = 'e', arr[4][5] = 'i';
        arr[5][1] = 'u', arr[5][2] = 'a', arr[5][3] = 'e', arr[5][4] = 'i', arr[5][5] = 'o';

        for(int i = 6; i <= n; ++i){
            arr[i][1] = 'a', arr[i][2] = 'e', arr[i][3] = 'i', arr[i][4] = 'o', arr[i][5] = 'u';
        }
        for(int i = 6; i <= m; ++i) { 
            arr[1][i] = 'a', arr[2][i] = 'e', arr[3][i] = 'i', arr[4][i] = 'o', arr[5][i] = 'u';
        }

        for(int i =  1; i <= n; ++i) { 
            for(int j = 1; j <= m; ++j) { 
                cout << arr[i][j];
            }
        }
        cout << endl;
    }
}    

int main() {
    double start = clock();
    int tc = 1;
    while(tc--) {
       solve();
    }
    cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
    return 0;
}
