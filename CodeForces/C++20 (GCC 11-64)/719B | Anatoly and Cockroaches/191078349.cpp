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
 
int n; string s;
int main()
{
 file();
 cin >> n >> s;
 
 string t1 = "", t2 = "";
 for(int i=0;i<n/2;i++){
  t1 += "rb";
  t2 += "br";
 }
 if(n % 2 == 1){
  t1 += "r"; t2 += "b";
 }
 
 int r1 = 0, b1 = 0;
 int r2 = 0, b2 = 0;
 for(int i=0;i<n;i++){
  if(s[i] != t1[i]){
   if(t1[i] == 'r') ++r1;
   else ++b1;
  }
  if(s[i] != t2[i]){
   if(t2[i] == 'r') ++r2;
   else ++b2;
  }
 }
 cout << min(max(r1, b1), max(r2, b2));
 return 0;
}