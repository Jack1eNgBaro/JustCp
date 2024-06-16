#include <bits/stdc++.h>
using namespace std;
 
 
#define input cin
#define output cout
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) u & - u;
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)
#define vi vector<int>
#define int128 __int128
 
const int cs = 2e5 + 5;
const int mod = 1e9 + 7;
const int INF = mod;
const int maxN = 5e3 + 7;
const int block_size = 350;
const ll oo = 1e18 + 7;
const int base = 31;
 
int t;
string s[2];
int q,BlockTime;
ll Tree[4 * cs];
int Leaf[cs];
int Time[4*cs];
 
void BuildTree(int id,int left,int right) {
    if (left == right) {
        Tree[id] = (s[0][left] != s[1][right]);
        Leaf[left] = id; 
        return;
    }
    int mid = (left + right) >> 1;
    BuildTree(id * 2,left,mid);
    BuildTree(id * 2 + 1,mid + 1,right);
    Tree[id] = Tree[id << 1] + Tree[id << 1 | 1];
};
 
void updateBlock(int u) {
    int id = Leaf[u];
    Tree[id] = 0;
    id >>= 1;
    while (id) {
        Tree[id] = Tree[id << 1] + Tree[id << 1 | 1];
        id >>= 1;
    }
}
 
void updateSwap(int u) {
    int id = Leaf[u];
    Tree[id] = (s[0][u] != s[1][u]);
    id >>= 1;
    while (id) {
        Tree[id] = Tree[id << 1] + Tree[id << 1 | 1];
        id >>= 1;
    }
}
 
 
void QuerySwap(int id1,int pos1,int id2,int pos2) {
    id1--;
    id2--;
    swap(s[id1][pos1],s[id2][pos2]);
    updateSwap(pos1);
    updateSwap(pos2);
}
 
void Solve() {
    input.ignore();
    getline(input,s[0]);
    getline(input,s[1]);
    int n = s[0].length();
    s[0] = '0' + s[0];
    s[1] = '0' + s[1];
    input >> BlockTime >> q;
    mem(Time,0);
    BuildTree(1,1,n);
    for (int i = 1;i<=q;i++) {
        int type;
        input >> type;
        if (Time[i] != 0) {
            updateSwap(Time[i]);
        }
        if (type == 1) {
            int x;
            input >> x;
            updateBlock(x);
            Time[i + BlockTime] = x;
        } else if (type == 2) {
            int id1,pos1,id2,pos2;
            input >> id1 >> pos1 >> id2 >> pos2;
            QuerySwap(id1,pos1,id2,pos2);
        } else {
            if (Tree[1] == 0) {
                output << "YES" << endl;
            } else {
                output << "NO" << endl;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input >> t;
    while (t--) {
        Solve();
    }
    return 0;
}