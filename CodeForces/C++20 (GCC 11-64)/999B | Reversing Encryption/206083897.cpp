/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int main()
{
 file();
 int n; cin >> n;
 string s; cin >> s;
 set<int> se;
 for(int i=1;i<=n;i++){
  if(n % i == 0){
   se.insert(i);
   se.insert(n / i);
  }
 }
 for(auto x: se){
  reverse(s.begin(), s.begin() + x);
 }
 cout << s;
 return 0;
}