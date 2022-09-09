#include <bits/stdc++.h>
#define LOCAL true
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

};


string input_string_with_spaces() { 
    #define MAX_SIZE 1000
    char x;
    while((x = getchar() ) == '\n');
    char input[MAX_SIZE];
    cin.getline(input, MAX_SIZE, '\n');
    string a = "";
    a += x;
    a += string(input);
    return a;
}



void solve() {
    string s1 = input_string_with_spaces(); 
    string s2 = input_string_with_spaces(); 

    unordered_map<char, int, custom_hash>mp;
    for(int i = 0; i < s1.size(); ++i) { 
        if(s1[i] == ' ')
            continue; 
        mp[s1[i]]++;   
    }
    bool ok = true;
    for(int i = 0; i < s2.size(); ++i) {
        if(s2[i] == ' ')
            continue;
        if(!mp[s2[i]]){
            ok = false;
            break;
        }
        mp[s2[i]]--;
    }
    cout << (ok ? "YES": "NO") << endl;
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
