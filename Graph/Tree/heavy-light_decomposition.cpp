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

const int maxN = 1e5 + 5;
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

/*
###################
##    PREPARE    ##
###################
*/

// Input
int n;
int val[maxN];

// Tree
vector<int> adj[maxN];
int sz[maxN];
int par[maxN];
int h[maxN];

void calc(int u, int p = 0)
{
    sz[u] = 1;

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        
        par[v] = u;
        h[v] = h[u] + 1;

        calc(v, u);

        sz[u] += sz[v];
    }
}

// Segment Tree
struct Segment_Tree
{
    int *pArr;
    ll ST[4 * maxN];

    Segment_Tree(int *p) : pArr(p) {}

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

        ST[id] = ST[2 * id] + ST[2 * id + 1];
    }

    void update(int id, int l, int r, int i, int v)
    {
        if (i < l || r < i)
            return;

        if (l == r)
        {
            ST[id] = v;
            return;
        }

        int mid = MID(l, r);

        update(2 * id, l, mid, i, v);
        update(2 * id + 1, mid + 1, r, i, v);

        ST[id] = ST[2 * id] + ST[2 * id + 1];
    }

    ll get(int id, int l, int r, int u, int v)
    {
        if (r < u || v < l)
        {
            return 0;
        }

        if (u <= l && r <= v)
        {
            return ST[id];
        }

        int mid = MID(l, r);

        return get(2 * id, l, mid, u, v) + get(2 * id + 1, mid + 1, r, u, v);
    }
};

/*
###############
##    HLD    ##
###############
*/

int flat[maxN];

int pos[maxN];
int curpos = 0;

int chain_id[maxN];
int chain_head[maxN];
int curchain = 0;

void HLD(int u, int p = 0)
{
    if (!chain_head[curchain])
    {
        chain_head[curchain] = u;
    }

    chain_id[u] = curchain;
    pos[u] = ++curpos;
    flat[pos[u]] = val[u]; 

    int nxt = 0;

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        
        if (sz[v] > sz[nxt])
            nxt = v;
    }

    if (nxt) HLD(nxt, u);
    for (int v : adj[u])
    {
        if (v == p || v == nxt)
            continue;
        
        ++curchain;

        HLD(v, u);   
    }
}

Segment_Tree segtree(flat);

void hld_update(int s, int x)
{
    val[s] = x;
    flat[pos[s]] = x;
    segtree.update(1, 1, n, pos[s], x);
}

ll hld_get(int u, int v)
{
    ll res = 0;

    while (chain_id[u] != chain_id[v])
    {
        if (h[u] > h[v])
            swap(u, v);

        res += segtree.get(1, 1, n, pos[chain_head[chain_id[v]]], pos[v]);

        v = par[chain_head[chain_id[v]]];
    }
    
    if (h[u] > h[v])
        swap(u, v);
    
    res += segtree.get(1, 1, n, pos[u], pos[v]);

    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    // ## INPUT

    // sz, par, h
    calc(1);

    // Build HLD Chain
    HLD(1);

    // Build ST
    segtree.build(1, 1, n);

    return 0;
}