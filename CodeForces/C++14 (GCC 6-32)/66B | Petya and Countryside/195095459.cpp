#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
const int maxn = 2e5;
 
int n;
int a[maxn + 1];
 main() {
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    int ans = 1;
    for(int i=1;i<=n;i++){
        int l = i, r = i;
        int cnt = 1;
        while(l >= 2 && a[l - 1] <= a[l]) --l, ++cnt;
        while(r <= n - 1 && a[r] >= a[r + 1]) ++r, ++cnt;
        ans = max(ans, cnt);
    }
    cout << ans;
 return 0;
}