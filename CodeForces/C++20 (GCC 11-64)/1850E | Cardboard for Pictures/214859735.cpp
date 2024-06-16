#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#define MOD 1000000007
#define fi first
#define se second
#define ii pair<int,int>
#define Dennis ""
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define el cout << '\n'
#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Fod(i, a, b) for(int i = (a); i >= (b); i--)
#define bit(x, i) ((x >> i) & 1)
 
template<class integer>
inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c) {
        static const int d[] = {'a'-10,'0'}; 
        return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i; 
    return sign ? -x : x; }
 
template<class integer>
inline string to_string(integer x, int base = 10) {
    bool sign = false; string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d) {
        static const char c[] = {'a'-10,'0'};
        return c[d < 10]+d; };
    do 
        s += digit_to_char(x%base), x /= base;
    while (x > 0); 
    if (sign)
        s += '-';
    reverse(s.begin(),s.end());
    return s; }
 
template<class integer>
inline istream& read(istream& is, integer& x) {
    string s; is >> s, x = to_int<integer>(s); return is; }
 
template<class integer>
inline ostream& write(ostream& os, integer x) { return os << to_string(x); }
 
using  lll =   signed __int128; 
using ulll = unsigned __int128;
 
inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }
 
#define input cin
#define output cout
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) u & - u;
#define mask(i) (1ll << i)
#define vi vector<int>
#define name_in "input.inp"
#define name_out "output.out"
 
// ifstream input(name_in);
// ofstream output(name_out);
 
const int cs = 1e6 + 7;
const int mod = 1e9 + 7;
const int INF = mod;
const int maxN = 5e3 + 7;
const int block_size = 350;
const ll oo = 1e18 + 7;
 
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
 
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
} else return false;
    }
 
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
 
template<class X, class Y>
    void Add(X &x , const Y &y) {
        x += y;
        if (x > mod) x -= mod;
    }
 
template<class X, class Y>
    void Sub(X &x, const Y &y) {
        x -= y;
        if (x < 0) x += mod;
    }
 
// 
 
#define int __int128
const int N = 1e6 + 5;
int a[N], n, c;
 
int cal(int mid){
 int sum = 0;
 For(i,1,n){
  int tmp = (a[i]+2*mid)*(a[i]+2*mid); 
  if(sum > c) return c + 1;
  if(c - sum < tmp) return c + 1;
  sum += tmp;
 }
 return sum;
}
 
void solve(){
    int tc; cin >> tc;
    while(tc--){
     cin >> n >> c;
     For(i,1,n) cin >> a[i];
     int l = 1, r = 1e18;
     int ans = 0;
     while(l <= r){
      int m = (l + r) / 2;
      int tmp = cal(m);
      if(tmp == c){
       ans = m;
       break;
      }else if(tmp > c){
       r = m - 1;
   }
      else{
       l = m + 1;
   }
     }
     cout << ans << "\n";
    }
}
 
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}