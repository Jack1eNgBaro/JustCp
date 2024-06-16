/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
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
 
struct Rect{
 int x1, y1, x2, y2;
 int S(){
  return abs(x1 - x2) * abs(y1 - y2);
 }
};
 
Rect A, B, C;
void nhap(Rect &A){
 cin >> A.x1 >> A.y1 >> A.x2 >> A.y2;
}
 
void in(Rect A){
 cout << A.x1 << " " << A.y1 << " " << A.x2 << " " << A.y2 << "\n";
}
 
Rect giao(Rect A, Rect B){
 int x1 = max(A.x1, B.x1);
 int y1 = max(A.y1, B.y1);
 int x2 = min(A.x2, B.x2);
 int y2 = min(A.y2, B.y2);
 if(x2 - x1 <= 0 || y2 - y1 <= 0) return {0, 0, 0, 0};
 return {x1, y1, x2, y2};
}
 
main()
{
 file();
 nhap(A); nhap(B); nhap(C);
 auto g1 = giao(A, B), g2 = giao(A, C), t = giao(g1, g2);
 int ans = A.S() - g1.S() - g2.S() + t.S();
 if(ans > 0) cout << "YES\n";
 else cout << "NO\n";
 return 0;
}