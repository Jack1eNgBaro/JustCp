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
 
int ktf(int a){
 if(a % 2 == 0) return 1;
 if(a % 3 == 0) return 1;
 if(a % 5 == 0) return 1;
 return 0;
}
 
int main()
{
 file();
 
 int a, b; cin >> a >> b;
 int a2 = 0, a3 = 0, a5 = 0;
 while(a % 2 == 0) a /= 2, a2++;
 while(a % 3 == 0) a /= 3, a3++;
 while(a % 5 == 0) a /= 5, a5++;
 
 int b2 = 0, b3 = 0, b5 = 0;
 while(b % 2 == 0) b /= 2, b2++;
 while(b % 3 == 0) b /= 3, b3++;
 while(b % 5 == 0) b /= 5, b5++;
 
 if(a != b) return cout << -1, 0;
 int ans = abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5);
 cout << ans;
 
 return 0;
}