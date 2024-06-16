#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 32000;
int p[maxn + 1];
vector<int> v;
 
void sieve()
{
 p[0] = p[1] = 1;
 for(int i=2;i<=sqrt(maxn);i++){
  if(p[i] == 0) for(int j=i*i;j<=maxn;j+=i) p[j] = 1;
 }
 for(int i=2;i<=maxn;i++) 
  if(p[i] == 0) v.push_back(i);
}
 
int sol(int a[], int n)
{
 for(int x: v)
 {
  int cnt = 0;
  for(int i=0;i<n;i++){
   if(a[i] % x == 0){
    ++cnt; 
    while(a[i] % x == 0) a[i] /= x;
   }
  }
  if(cnt >= 2) return 1;
 }
 sort(a, a + n);
 for(int i=1;i<n;i++){
  if(a[i] == a[i - 1] && a[i] > 1) return 1;
 }
 return 0;
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 sieve();  
 
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  int a[n]; for(int &i: a) cin >> i;
  if(sol(a, n)) cout << "YES\n";
  else cout << "NO\n";
 }  
   
 return 0;
}