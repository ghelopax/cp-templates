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

// Bridge Tree
struct BridgeTree
{
    int cur;
    int id[maxN];
    int nodesize[maxN];
    vector<int> adj[maxN];

    BridgeTree() : cur(0) {}

    void addEdge(int u, int v)
    {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    void build()
    {
        for (const Edge &e : G.edges)
            if (id[e.u] != id[e.v])
                addEdge(id[e.u], id[e.v]);
    }
} BT;

// DFS Tree of G
int tin[maxN];
int low[maxN];
int timer = 0;
bool del[maxN]; // Tarjan
stack<int> st;

void calc(int u, int p = 0)
{
    tin[u] = low[u] = ++timer;
    st.push(u);

    for (int v : G.adj[u])
    {
        if (del[v]) continue;
        if (v == p) continue;

        if (tin[v]) low[u] = min(low[u], tin[v]);
        else
        {
            calc(v, u);
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

            ++BT.nodesize[BT.cur];
            BT.id[v] = BT.cur;
            del[v] = true;
        }
        while (v != u);
    }
}

void preprocess()
{
    calc(1);
    BT.build();
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);

    input();

    preprocess();

    return 0;
}