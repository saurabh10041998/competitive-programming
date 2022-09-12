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
    int n = sza(str);
    char l1 = '!';
    for(int i = 0; i < n; i += 4) { 
        if(str[i] != l1) {
            l1 = str[i];
            break;
        }
    }
    assert(l1 != '!');
    char l2 = '!';
    for(int i = 1; i < n; i += 4) { 
        if(str[i] != l2) {
            l2 = str[i];
            break;
        }
    }
    assert(l2 != '!');
    char l3 = '!';
    for(int i = 2; i < n; i += 4) { 
        if(str[i] != l3) { 
            l3 = str[i];
            break;
        }
    }
    assert(l3 != '!');
    char l4 = '!';
    for(int i = 3; i < n; i += 4) { 
        if(str[i] != l4) { 
            l4 = str[i];
            break;
        }
    }
    assert(l4 != '!');
    map<char, int>mp;
    for(int i = 0; i < n; i += 4) { 
        if(str[i] != l1) { 
            mp[l1]++;
        }
    }
    for(int i = 1; i < n; i += 4) { 
        if(str[i] != l2) { 
            mp[l2]++;
        }        
    }
    for(int i = 2; i < n; i += 4) { 
        if(str[i] != l3){
            mp[l3]++;
        }
    }
    for(int i = 3; i < n; i += 4) { 
        if(str[i] != l4) {
            mp[l4]++;
        }
    }
    cout << mp['R'] << " " << mp['B'] << " " << mp['Y'] << " " << mp['G'] << endl;
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
