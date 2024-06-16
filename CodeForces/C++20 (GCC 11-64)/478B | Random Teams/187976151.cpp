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
 
int c2(int x){
 return x * (x - 1) / 2;
}
 
main()
{
 file();
 int n, m;
 cin >> n >> m;
 
 int a = n / m;
 int b = n % m;
 
 int k1 = c2(a) * (m - b);
 int k2 = c2(a + 1) * b;
 int kmi = k1 + k2;
 
 int kmx = c2(n - m + 1);
 cout << kmi << " " << kmx;
 
 return 0;
}