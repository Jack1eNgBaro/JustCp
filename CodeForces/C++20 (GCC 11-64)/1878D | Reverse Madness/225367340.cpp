#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
#define MOD 1000000007
#define fi first
#define se second
#define ll long long
#define LL long long
#define ii pair<int,int>
#define Dennis ""
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define el cout << '\n'
#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Fod(i, a, b) for(int i = (a); i >= (b); i--)
#define bit(x, i) ((x >> i) & 1)
 
using namespace std;
template <class X, class Y> bool minimize(X &a, Y b){
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b){
    if (a < b) return a = b, true;
    return false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {return l + rng() % (r - l + 1);}
const int N = 1e6 + 5;
 
typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    LL sum;
    bool rev;
 
    item(int value):prior(rng()), value(value) {
        cnt = 0;
        rev = 0;
        sum = value;
        l = r = nullptr;
    }
 
    pitem l, r;
};
 
class Treap {
public:
    int cnt (pitem it) {
        return it != nullptr? it->cnt : 0;
    }
    LL sum(pitem it) {
        return it != nullptr? it->sum : 0;
    }
    void upd_cnt (pitem it) {
        if (it!=nullptr) {
            it->cnt = cnt(it->l) + cnt(it->r) + 1;
            it->sum = sum(it->l) + sum(it->r) + it->value;
        }
    }
    void push (pitem it) {
        if (it != nullptr && it->rev == true) {
            it->rev = false;
            swap (it->l, it->r);
            if (it->l)  it->l->rev ^= true;
            if (it->r)  it->r->rev ^= true;
        }
    }
    void merge (pitem & t, pitem l, pitem r) {
        push (l);
        push (r);
        if (l==nullptr || r==nullptr)
            t = (l!=nullptr) ? l : r;
        else if (l->prior > r->prior)
            merge (l->r, l->r, r),  t = l;
        else
            merge (r->l, l, r->l),  t = r;
        upd_cnt (t);
    }
    void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
        if (t==nullptr) {
            l = r = nullptr;
            return;
        }
        push(t);
        int cur_key = add + cnt(t->l);
 
        if (key <= cur_key)
            split (t->l, l, t->l, key, add),  r = t;
        else
            split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
        upd_cnt (t);
    }
    void reverse (pitem &t, int l, int r) {
        pitem t1, t2, t3;
        split (t, t1, t2, l);
        split (t2, t2, t3, r-l+1);
        assert(t2 != NULL);
        t2->rev ^= true;
        merge (t, t1, t2);
        merge (t, t, t3);
    }
    LL query (pitem &t, int l, int r) {
        pitem t1, t2, t3;
        split (t, t1, t2, l);
        split (t2, t2, t3, r-l+1);
        LL ans = t2->sum;
        merge (t, t1, t2);
        merge (t, t, t3);
        return ans;
    }
    void insert (pitem & t, int key, int value) {
        pitem x = new item(value);
        pitem L, R;
        split(t, L, R, key);
        merge(L, L, x);
        merge(t, L, R);
        upd_cnt(t);
    }
    int erase (pitem & t, int key) {
        assert(cnt(t) > key);
        pitem L, MID, R;
        split(t, L, MID, key);
        split(MID, MID, R, 1);
        merge(t, L, R);
        upd_cnt(t);
        int rt = MID->value;
        delete MID;
        return rt;
    }
    void output (pitem t, string &v) {
        if (t==nullptr)  return;
        push (t);
        output (t->l, v);
        v.push_back(t->value);
        output (t->r, v);
    }
    void output2 (pitem t) {
        if (t==nullptr)  return;
        push (t);
//        cout << "(";
        output2 (t->l);
        cout << (t->value) << " ";
        output2 (t->r);
//        cout << ")";
    }
};
 
int len, n, Q;
string str;
 
void solve(){
    Treap god;
    pitem tr = nullptr;
 
    cin >> len >> n;
    cin >> str;
   
    // cout << n << " " << Q << " " << str << "\n";
    vector<int> l(n + 1, 0), r(n + 1, 0);
    For(i,1,n) cin >> l[i];
    For(i,1,n) cin >> r[i];
 
    For(i,0,len-1){
        char ch = str[i];
        god.insert(tr, i, ch);
    }
 
    cin >> Q;
    while(Q--){
        int x; cin >> x;
        int it = upper_bound(all(l), x) - l.begin() - 1;
        int lef = min(x, l[it] + r[it] - x);
        int rig = max(x, l[it] + r[it] - x);
        --lef; --rig;
        god.reverse(tr, lef, rig);
    }
    string ans;
    god.output(tr, ans);
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int bla = uniform_int_distribution<int>(1, 100)(rng);
    #define TASK ""
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}