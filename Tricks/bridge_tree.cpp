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
#define pii pair<int, int>

const int maxN = 2e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFLL = 4e18;
const int LG = 20;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))

/*
    Bridge Tree:
    
    DSU + Tarjan (DFS Tree)
*/

void input()
{
}

// Disjoint Set Union
struct DSU
{
    int lab[maxN];

    void init(int sz)
    {
        fill(lab + 1, lab + sz + 1, -1);
    }

    int find(int u)
    {
        return (lab[u] < 0 ? u : lab[u] = find(lab[u]));
    }

    bool join(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v)
            return false;

        if (lab[u] > lab[v])
            swap(u, v);

        lab[u] += lab[v];
        lab[v] = u;

        return true;
    }
};

namespace Subtask_4
{
    bool constraint()
    {
        return true;
    }

    // DSU
    DSU dsu;

    // Bridge Tree
    int curid = 0;
    int id[maxN];      // BT nodes ID
    bool vst[maxN];

    vector<int> adj[maxN]; // Some useful infos of BT
    int deg[maxN];
    int nodesize[maxN];

    void build(int u)
    {
        for (int v : adj[u])
        {
            if (vst[v]) continue;

            vst[v] = true;

            // BT edges
            if (dsu.join(id[u], id[v]))
            {
                adj[id[u]].pb(id[v]);
                adj[id[v]].pb(id[u]);

                ++deg[id[u]], ++deg[id[v]];
            }

            build(v);
        }
    }

    // DFS Tree
    int timer = 0;
    int num[maxN], low[maxN];

    // Tarjan
    stack<int> st;
    bool del[maxN];

    void calc(int u, int p = 0)
    {
        num[u] = low[u] = ++timer;
        st.push(u);

        for (int v : adj[u])
        {
            if (del[v]) continue;
            if (v == p) continue;

            if (!num[v])
            {
                calc(v, u);

                low[u] = min(low[u], low[v]);
            }
            else low[u] = min(low[u], num[v]);
        }

        // BT nodes
        if (low[u] == num[u])
        {
            ++curid;
            int v;

            do
            {
                v = st.top(); st.pop();

                ++nodesize[curid];
                id[v] = curid;
                del[v] = true;
            }
            while (v != u);
        }
    }

    void preprocess()
    {
        // Tarjan with root = 1
        calc(1);

        // Build Bridge Tree with BT's root = 1
        dsu.init(curid);
        vst[1] = true;
        build(1);
    }

    void solve()
    {
        
    }

    void run()
    {
        preprocess();
        solve();
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

    if (Subtask_4::constraint()) return Subtask_4::run(), 0;

    return 0;
}