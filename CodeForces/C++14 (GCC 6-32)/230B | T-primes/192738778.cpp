#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int p[maxn + 1];
void sieve(){
 for(int i=0;i<=maxn;i++) p[i] = 1;
 p[0] = p[1] = 0;
 for(int i=2;i<=sqrt(maxn);i++){
  if(p[i] == 1) for(int j=i*i;j<=maxn;j+=i) p[j] = 0;
 }
}
 
main()
{
 file();
 sieve();
 int n; cin >> n;
 while(n--){
  int x; cin >> x;
  int t = sqrt(x);
  if(t * t == x && p[t]) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}