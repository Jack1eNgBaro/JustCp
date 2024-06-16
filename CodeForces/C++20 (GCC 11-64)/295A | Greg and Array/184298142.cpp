#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 ll n, m, k; cin >> n >> m >> k;
 vector<pair<pii,ll>> v(m + 1);
 
 ll a[n + 1];
 for(ll i=1;i<=n;i++) cin >> a[i];
 
 for(ll i=1;i<=m;i++)
  cin >> v[i].first.first >> v[i].first.second >> v[i].second;
 
 ll cnt[m + 1];
 memset(cnt, 0, sizeof(cnt));
 for(ll i=1;i<=k;i++)
 {
  ll l, r; cin >> l >> r;
  cnt[l]++; cnt[r + 1]--;
 }
 for(ll i=1;i<=m;i++) cnt[i] += cnt[i - 1];
 
// cout << "\n"; for(ll i=1;i<=m;i++) cout << cnt[i] << " "; cout << "\n";
 
 ll pf[n + 1];
 memset(pf, 0, sizeof(pf));
 
 for(ll i=1;i<=m;i++)
 {
  ll l = v[i].first.first;
  ll r = v[i].first.second;
  ll d = v[i].second;
  d = d * cnt[i];
  
//  cout << l << ' ' << r << ' ' << d << '\n';
  
  pf[l] += d;
  pf[r + 1] -= d;
 }
 for(ll i=1;i<=n;i++) pf[i] += pf[i - 1];
 
 for(ll i=1;i<=n;i++) cout << a[i] + pf[i] << " ";  
   
 return 0;
}