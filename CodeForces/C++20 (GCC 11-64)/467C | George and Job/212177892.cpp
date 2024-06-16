#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 5003
using namespace std;
int n, m, k;
int a[maxn];
long long s[maxn], f[maxn][maxn];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    f1 (i, n) cin >> a[i], s[i] = s[i-1] + a[i];
    for (int i=m; i<=n; ++i)
    {
        for (int j=0; j<=k; ++j)
            f[i][j] = f[i-1][j];
        for (int j=1; j<=k; ++j)
            f[i][j] = max(f[i][j], f[i-m][j-1] + s[i] - s[i-m]);
    }
    cout << f[n][k];
}