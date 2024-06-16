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
 string s; cin >> s;
 int cl1 = -1, cl2 = -1;
 int cr1 = -1, cr2 = -1;
 for(int i=0;i<n;i++){
  if(s[i] == 'L' && cl1 == -1){
   cl1 = i + 1;
  }
  if(s[i] == 'R' && cr1 == -1){
   cr1 = i + 1;
  }
  if(s[i] == 'L') cl2 = i + 1;
  if(s[i] == 'R') cr2 = i + 1;
 }
 if(cl1 != -1 && cr1 == -1){
  cout << cl2 << ' ' << cl1 - 1;
 }else if(cl1 == -1 && cr1 != -1){
  cout << cr1 << ' ' << cr2 + 1;
 }else{
  cout << cl1 << ' ' << cr2;
 }
 return 0;
}