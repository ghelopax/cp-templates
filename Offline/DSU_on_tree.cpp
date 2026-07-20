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

/*
    Codeforces 375D
*/

#define ll long long
#define ldb long double

const int maxN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFLL = 4e18;
const int LG = 20;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define BIT(msk, i) (((msk) >> (i)) & 1LL)
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))
#define FOR(i, l, r) for (int i = (l); i <= (int)(r); ++i)
#define FORLL(i, l, r) for (ll i = (l); i <= (ll)(r); ++i)
#define isz(v) (int)v.size()

int N;
int c[maxN];
vector<int> adj[maxN];
int Q;

void input()
{
    cin >> N >> Q;

    FOR(i, 1, N) cin >> c[i];

    for (int u, v, i = 0; i < N - 1; ++i)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

namespace Subtask_1
{
    const int maxQ = 1e5 + 5;

    bool constraint()
    {
        return true;
    }

    int cnt[maxN];

    struct BIT
    {
        int bit[maxN];

        void update(int i, int w)
        {
            for (; i <= N; i += lsb(i)) bit[i] += w;
        }

        int get(int i)
        {
            int res = 0;
            for (; i > 0; i -= lsb(i)) res += bit[i];
            return res;
        }
    } ft;

    // Tree
    int h[maxN];
    int sz[maxN];

    // Euler Tour
    int tin[maxN], tout[maxN];
    int ver[maxN];
    int timer;

    void calc(int u, int p = 0)
    {
        sz[u] = 1;
        tin[u] = ++timer;
        ver[tin[u]] = u;
        
        for (int v : adj[u])
        {
            if (v == p) continue;

            h[v] = h[u] + 1;

            calc(v, u);

            sz[u] += sz[v];
        }

        tout[u] = timer;
    }

    // Offline query
    // DSU on Tree
    struct Query
    {
        int id;
        int k;

        Query(int _id, int _k) : id(_id), k(_k) {}
    };
    vector<Query> queries[maxN];
    int ans[maxQ];

    void add(int u)
    {
        if (cnt[c[u]]) ft.update(cnt[c[u]], -1);
        ++cnt[c[u]];
        ft.update(cnt[c[u]], 1);
    }

    void rem(int u)
    {
        ft.update(cnt[c[u]], -1);
        --cnt[c[u]];
        if (cnt[c[u]]) ft.update(cnt[c[u]], 1);
    }

    void query(int u, int p, bool heavy)
    {
        int nxt = 0;
        for (int v : adj[u])
        {
            if (v == p) continue;
            if (sz[nxt] < sz[v]) nxt = v;
        }

        for (int v : adj[u])
        {
            if (v == p || v == nxt) continue;
            query(v, u, false);
        }
        if (nxt) query(nxt, u, true);

        for (int v : adj[u])
        {
            if (v == p || v == nxt) continue;
            FOR(t, tin[v], tout[v]) add(ver[t]);
        }

        add(u);

        for (Query qr : queries[u])
            ans[qr.id] = (qr.k > N ? 0 : ft.get(N) - (qr.k > 1 ? ft.get(qr.k - 1) : 0));

        if (!heavy) FOR(t, tin[u], tout[u]) rem(ver[t]);
    }

    void preprocess()
    {
        timer = 0;
        sz[0] = 0;
        h[1] = 0;
        calc(1);
    }

    void getQuery(int id)
    {
        int v, k;
        cin >> v >> k;

        queries[v].eb(id, k);
    }

    void run()
    {
        preprocess();
        FOR(i, 0, Q - 1) getQuery(i);
        query(1, 0, false);
        FOR(i, 0, Q - 1) cout << ans[i] << el;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    input();

    if (Subtask_1::constraint()) return Subtask_1::run(), 0;

    return 0;
}