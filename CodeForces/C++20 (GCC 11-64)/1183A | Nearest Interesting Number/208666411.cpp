/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
#define fi first
#define se second
#define vi vector<int> 
 
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
 
int kt(int n){
 int s = 0;
 while(n){
  s += (n%10);
  n /= 10;
 } 
 return s % 4 == 0;
}
 
int main()
{
 file();
 int n; cin >> n;
 while(1 + 1 == 2){
  if(kt(n)) return cout << n, 0;
  ++n;
 }
 return 0;
}