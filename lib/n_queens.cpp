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


void _solve(
        int n ,
        int col, 
        vector<int>& left, 
        vector<int>&upperleft, 
        vector<int>& lowerleft,
        vector<string> &board, 
        vector<vector<string>> &ans) {
    if(col == n ) {
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; ++row) {
        if(left[row] == 0 && upperleft[(n-1) + (col - row)] == 0 && lowerleft[row + col] == 0) {
            board[row][col] = 'Q';
            left[row] = 1;
            upperleft[(n - 1) + (col - row)] = 1;
            lowerleft[row + col] = 1;
            _solve(n, col + 1, left, upperleft, lowerleft, board, ans);
            board[row][col] = '.';
            left[row] = 0;
            upperleft[(n-1) + (col - row)] = 0;
            lowerleft[row + col] = 0;
        }
    }
}


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>board;
    vector<int>left(n - 1, 0);
    vector<int>upperleft(2 * n - 1, 0);
    vector<int>lowerleft(2 * n - 1, 0);
    for(int i = 0; i < n; ++i) {
        board.push_back(string(n, '.'));
    }
    _solve(n, 0, left, upperleft, lowerleft, board, ans);
    return ans;
}

void solve() {
    vector<vector<string>> ans8 = solveNQueens(4);
    dbg(ans8);
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
