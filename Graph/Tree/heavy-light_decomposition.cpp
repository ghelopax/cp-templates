#include <bits/stdc++.h>

using namespace std;

/*
 /\_/\  /\_/\  /\_/\  /\_/\
( o.o )( o.o )( o.o )( o.o )
 > ^ <  > ^ <  > ^ <  > ^ <
 /\_/\                /\_/\
( o.o )   ghelopax   ( o.o )
 > ^ <                > ^ <
 /\_/\  /\_/\  /\_/\  /\_/\
( o.o )( o.o )( o.o )( o.o )
 > ^ <  > ^ <  > ^ <  > ^ <
*/

#define ll long long
#define ldb long double

const int maxN = 2e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 2e9;
const ll INFLL = 4e18;
const int LG = 20;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))

// Input
int n;
int val[maxN];

// Tree
vector<int> adj[maxN];
int sz[maxN];
int h[maxN];
int par[maxN];

void calc(int u)
{
    sz[u] = 1;

    for (int v : adj[u])
    {
        if (v == par[u])
            continue;

        h[v] = h[u] + 1;
        par[v] = u;

        calc(v);

        sz[u] += sz[v];
    }
}

// Segment Tree
ll ST[4 * maxN];

struct Segment_Tree
{
    ll *pArr;

    Segment_Tree(ll *p) : pArr(p) {}

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            ST[id] = pArr[l];
            return;
        }

        int mid = MID(l, r);

        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);

        ST[id] = ST[id << 1] + ST[id << 1 | 1];
    }

    void update(int id, int l, int r, int i, ll v)
    {
        if (l == r)
        {
            ST[id] = v;
            return;
        }

        int mid = MID(l, r);

        if (i > mid)
            update(id << 1 | 1, mid + 1, r, i, v);
        else
            update(id << 1, l, mid, i, v);

        ST[id] = ST[id << 1] + ST[id << 1 | 1];
    }

    ll get(int id, int l, int r, int u, int v)
    {
        if (r < u || v < l)
            return 0;
        
        if (u <= l && r <= v)
            return ST[id];

        int mid = MID(l, r);

        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
};

// Heavy - Light Decomposition
// Chain
int chead[maxN], cid[maxN];

// Flatten
ll flat[maxN];
int pos[maxN];

struct HLD
{
    int curc, curp;
    Segment_Tree seg;

    HLD() : curc(1), curp(0), seg(flat) {}

    void build(int u)
    {
        if (!chead[curc])
        {
            chead[curc] = u;
        }
        cid[u] = curc;

        pos[u] = ++curp;
        flat[pos[u]] = val[u];

        int nxt = 0;

        for (int v : adj[u])
        {
            if (v == par[u])
                continue;

            if (!nxt || sz[nxt] < sz[v])
                nxt = v;
        }

        if (!nxt)
            return;

        build(nxt);

        for (int v : adj[u])
        {
            if (v == par[u] || v == nxt)
                continue;
            
            ++curc;

            build(v);
        }
    }

    void preprocess()
    {
        build(1);
        seg.build(1, 1, n);
    }

    void update(int u, ll val)
    {
        seg.update(1, 1, n, pos[u], val);
    }

    ll get(int u, int v)
    {
        ll res = 0;

        while (cid[u] != cid[v])
        {
            if (h[chead[cid[u]]] < h[chead[cid[v]]])
                swap(u, v);

            res += seg.get(1, 1, n, pos[chead[cid[u]]], pos[u]);

            u = par[chead[cid[u]]];
        }

        if (h[u] > h[v])
            swap(u, v);

        res += seg.get(1, 1, n, pos[u], pos[v]);

        return res;
    }
} hld;

void solve()
{
    // Build par[], sz[], h[]
    calc(1);

    // Build HLD
    hld.preprocess();

    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    solve();

    return 0;
}