#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
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
 
int main()
{
 file();
 int n; cin >> n;
 int a[n], b[n];
 for(int &i: a) cin >> i;
 for(int &i: b) cin >> i;
//ai - bi + aj - bj > 0 => luu vao c
 int c[n];
 for(int i=0;i<n;i++){
  c[i] = a[i] - b[i];
//  cout << c[i] << ' ';
 }
 
//Dem so cap ci + cj co tong lon hon 0
 sort(c, c + n);
 ll ans = 0;
// for(auto x: c) cout << x << ' '; cout << "\n";
 for(int i=0;i<n;i++){
  int j = upper_bound(c + i + 1, c + n, -c[i]) - c;
//  cout << i << ' ' << j << "\n";
  if(j == n) continue;
  ans += (n - j);
 }
 cout << ans;
 return 0;
}