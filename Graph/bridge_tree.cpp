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
    Codeforces 1000E
*/

#define NAME "main"

#define ll long long
#define ldb long double
#define pii pair<int, int>

const int maxN = 3e5 + 5;
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

struct Edge
{
    int u, v;

    Edge(int _u, int _v) : u(_u), v(_v) {}
};

int n, m;

struct Graph
{
    vector<int> adj[maxN];
    vector<Edge> edges;

    void addEdge(int u, int v)
    {
        adj[u].pb(v);
        adj[v].pb(u);
        edges.eb(u, v);
    }
} G;

void input()
{
    cin >> n >> m;

    for (int u, v, i = 0; i < m; ++i)
    {
        cin >> u >> v;
        G.addEdge(u, v);
    }
}

namespace Subtask_1
{
    bool constraint()
    {
        return true;
    }

    // Tree Diameter
    pii farthest(vector<int> *_adj, int _N, int s)
    {
        pii res(-1, 0);

        vector<bool> _vst(_N + 1, 0);
        queue<pii> q;
        q.emplace(s, 0);
        _vst[s] = true;

        while (!q.empty())
        {
            int u, du;
            tie(u, du) = q.front(); q.pop();

            if (res.second < du)
            {
                res.second = du;
                res.first = u;
            }

            for (const int &v : _adj[u])
            {
                if (_vst[v]) continue;
                _vst[v] = true;
                q.emplace(v, du + 1);
            }
        }

        return res;
    }

    int diameter(vector<int> *_adj, int _N)
    {
        int A = farthest(_adj, _N, 1).first;
        if (A == -1) return 0;
        return farthest(_adj, _N, A).second;
    }

    struct BridgeTree
    {
        int cur;
        int id[maxN];
        vector<int> adj[maxN];

        BridgeTree() : cur(0) {}

        void addEdge(int u, int v)
        {
            adj[u].pb(v);
            adj[v].pb(u);
        }

        void init()
        {
            for (const Edge &e : G.edges)
                if (id[e.u] != id[e.v])
                    addEdge(id[e.u], id[e.v]);
        }
    } BT;

    // DFS Tree of G
    int tin[maxN];
    int low[maxN];
    int timer;
    // Tarjan
    bool del[maxN];
    stack<int> st;

    void dfs(int u, int p = 0)
    {
        tin[u] = low[u] = ++timer;
        st.push(u);

        for (const int &v : G.adj[u])
        {
            if (del[v]) continue;
            if (v == p) continue;

            if (tin[v]) low[u] = min(low[u], tin[v]);
            else
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            }
        }

        if (low[u] == tin[u])
        {
            ++BT.cur;
            int v;
            do
            {
                v = st.top(); st.pop();

                BT.id[v] = BT.cur;
            }
            while (v != u);
        }
    }

    void preprocess()
    {
        timer = 0;
        dfs(1);
        BT.init();
    }

    void solve() // or: void query()
    {
        // FOR(i, 1, BT.cur)
        // {
        //     cerr << i << ": ";
        //     for (const int &v : BT.adj[i])
        //         cerr << v << ' ';
        //     cerr << el;
        // }

        cout << diameter(BT.adj, BT.cur);
    }

    void run()
    {
        preprocess();
        solve(); // or: while(Q--) query();
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if (fopen(NAME".inp", "r"))
    {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }

    input();

    if (Subtask_1::constraint()) return Subtask_1::run(), 0;

    return 0;
}