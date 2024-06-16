#include<bits/stdc++.h>
using namespace std;
 
#define int __int128
#define pii pair<int,int>
#define ll long long
 
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
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  
  // ans += 1 ^ 2 + 2 ^ 2 + 3 ^ 3 + ... + n ^ n    = n * (n + 1) * (2 * n + 1) / 6;
  // ans += 0 * 1 + 1 * 2 + 2 * 3 + ... + n * (n - 1)     = (n - 1) * n * (n + 1) / 3;
  /*
   S = 1 x 2 + 2 x 3 + ... + 99 x 100
   3S = 1 x 2 x 3 + 2 x 3 x (4 - 1) + ..... + 99 x 100 x (101 - 98)
   3S = 1 x 2 x 3 + 2 x 3 x 4 - 1 x 2 x 3 + .... + 99 x 100 x 101 - 98 x 99 x 100
   3S = 99 x 100 x 101 = 999900
   S = 999900 : 3 = 333300
  */
  
  int x = n * (n + 1) * (2 * n + 1) / 6;
  int y = (n - 1) * n * (n + 1) / 3;
  int ans = (x + y) % mod;
  cout << (2022 * ans) % mod << "\n";
 }
 return 0;
}