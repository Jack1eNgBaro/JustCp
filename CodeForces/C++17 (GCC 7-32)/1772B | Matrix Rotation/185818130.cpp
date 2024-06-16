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
 int tc; cin >> tc;
 while(tc--)
 {
  int a[2][2];
  for(int i=0;i<2;i++) for(int j=0;j<2;j++) cin >> a[i][j];
  
  int t1[2][2] = {{a[0][0], a[0][1]}, {a[1][0], a[1][1]}};
  int t2[2][2] = {{a[1][0], a[0][0]}, {a[1][1], a[0][1]}};
  int t3[2][2] = {{a[1][1], a[1][0]}, {a[0][1], a[0][0]}};
  int t4[2][2] = {{a[0][1], a[1][1]}, {a[0][0], a[1][0]}};
  
  int ok = 0;
  if(t1[0][0] < t1[0][1] && t1[0][0] < t1[1][0] && t1[0][1] < t1[1][1] && t1[1][0] < t1[1][1]) ok = 1;
  if(t2[0][0] < t2[0][1] && t2[0][0] < t2[1][0] && t2[0][1] < t2[1][1] && t2[1][0] < t2[1][1]) ok = 1;
  if(t3[0][0] < t3[0][1] && t3[0][0] < t3[1][0] && t3[0][1] < t3[1][1] && t3[1][0] < t3[1][1]) ok = 1;
  if(t4[0][0] < t4[0][1] && t4[0][0] < t4[1][0] && t4[0][1] < t4[1][1] && t4[1][0] < t4[1][1]) ok = 1;
  
  if(ok) cout << "YES\n";
  else cout << "NO\n";
  
 }
 return 0;
}