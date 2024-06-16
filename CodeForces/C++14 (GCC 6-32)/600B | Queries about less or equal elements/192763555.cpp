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
 
int n, m;
vector<int> a;
int main()
{
 file();
 cin >> n >> m;
 for(int i=0;i<n;i++){
  int x; cin >> x;
  a.push_back(x);
 }
 sort(a.begin(), a.end());
 while(m--){
  int x; cin >> x;
  auto it = upper_bound(a.begin(), a.end(), x);
  cout << it - a.begin() << " ";
 }
 return 0;
}