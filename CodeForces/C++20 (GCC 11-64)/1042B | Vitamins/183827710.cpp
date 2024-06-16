#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
 
int encode(string s)
{
    int ans = 0;
    for(int pos=0;pos<3;pos++)
    {
        char c = 'C' - pos;
        bool have = 0;
        for(auto d: s)
            if(c == d) have = 1;
        if(have) ans += (1 << pos);
    }
    return ans;
}
 
main() {
    
    int n; cin >> n;
    
    vector<pii> v;
    for(int i=0;i<n;i++)
    {
        int x;
        string st;
        cin >> x >> st;
        int y = encode(st);
        v.push_back({x, y});
    }
    
    int dp[n + 1][8];
    for(int i=0;i<=n;i++)   for(int j=0;j<8;j++)
    dp[i][j] = 1e9;
    
    dp[0][0] = 0;
    for(int i=0;i<n;i++)
    {
        int x = v[i].first;
        int y = v[i].second;
//        cout << x << ' ' << y << "\n";
        for(int j=0;j<8;j++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j | y] = min(dp[i + 1][j | y], dp[i][j] + x);
        }
    }
    
    int ans = dp[n][7];
    if(ans != 1e9) cout << ans;
    else cout << -1;
    
 return 0;
}