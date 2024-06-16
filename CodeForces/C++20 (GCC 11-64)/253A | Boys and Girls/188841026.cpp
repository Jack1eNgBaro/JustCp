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
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
}
 
int main()
{
 file();
 int n, m; cin >> n >> m;
 int k = min(n, m);
 for(int i=0;i<k;i++){
  if(m == k) cout << "BG";
  else cout << "GB";
 }
 if(n > k) for(int i=k;i<n;i++) cout << "B";
 else if(m > k) for(int i=k;i<m;i++) cout << "G";
 return 0;
}