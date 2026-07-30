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
int heavy[maxN];

void calc(int u)
{
    sz[u] = 1;
    for (int v : adj[u])
    {
        if (v == par[u]) continue;
        h[v] = h[u] + 1;
        par[v] = u;
        calc(v);
        sz[u] += sz[v];
        if (sz[heavy[u]] < sz[v]) heavy[u] = v;
    }
}

// Segment Tree (Lazy Propagation)
struct Segment_Tree
{
    private:
    ll *ptr;
    ll ST[4 * maxN];
    ll LZ[4 * maxN];

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            ST[id] = ptr[l];
            return;
        }

        int mid = MID(l, r);
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);

        ST[id] = ST[id << 1] + ST[id << 1 | 1];
    }

    void down(int id, int l, int r)
    {
        if (!LZ[id]) return;

        if (l != r)
        {
            ST[id << 1] += LZ[id];
            ST[id << 1 | 1] += LZ[id];
            LZ[id << 1] += LZ[id];
            LZ[id << 1 | 1] += LZ[id];
        }

        LZ[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, ll w)
    {
        if (r < u || v < l) return;
        if (l == r)
        {
            ST[id] += w;
            LZ[id] += w;
            return;
        }

        down(id, l, r);
        int mid = MID(l, r);
        update(id << 1, l, mid, u, v, w);
        update(id << 1 | 1, mid + 1, r, u, v, w);

        ST[id] = ST[id << 1] + ST[id << 1 | 1];
    }

    ll get(int id, int l, int r, int u, int v)
    {
        if (r < u || v < l) return 0;
        if (u <= l && r <= v) return ST[id];

        down(id, l, r);
        int mid = MID(l, r);
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }

    public:
    Segment_Tree(ll *_ptr) : ptr(_ptr) {}

    void build()
    {
        build(1, 1, n);
    }

    void update(int l, int r, ll w)
    {
        update(1, 1, n, l, r, w);
    }

    ll get(int l, int r)
    {
        return get(1, 1, n, l, r);
    }
};

// Heavy - Light Decomposition
struct HLD
{
    // Chain
    int chead[maxN], cid[maxN];
    int head(int u) { return chead[cid[u]]; }
    // Flatten
    ll flat[maxN];
    int pos[maxN];
    int ver[maxN];
    Segment_Tree st;
    
    int cur, timer;
    
    HLD() : cur(0), timer(0), st(flat) {}

    void build(int u)
    {
        cid[u] = cur;
        pos[u] = ++timer;
        ver[pos[u]] = u;
        flat[pos[u]] = val[u];

        int nxt = heavy[u];
        if (nxt) build(nxt);
        for (int v : adj[u])
        {
            if (v == par[u] || v == nxt) continue;
            chead[++cur] = v;
            build(v);
        }
    }

    void init()
    {
        chead[++cur] = 1;
        build(1);
        st.build();
    }

    void update(int u, int v, ll w)
    {
        while (cid[u] != cid[v])
        {
            if (h[head(u)] < h[head(v)]) swap(u, v);
            st.update(pos[head(u)], pos[u], w);
            u = par[head(u)];
        }

        if (h[u] > h[v]) swap(u, v);
        st.update(pos[u], pos[v], w);
    }

    ll get(int u, int v)
    {
        ll res = 0;

        while (cid[u] != cid[v])
        {
            if (h[head(u)] < h[head(v)]) swap(u, v);
            res += st.get(pos[head(u)], pos[u]);
            u = par[head(u)];
        }

        if (h[u] > h[v]) swap(u, v);
        res += st.get(pos[u], pos[v]);

        return res;
    }
} hld;

void solve()
{
    calc(1);
    // Build HLD
    hld.init();
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