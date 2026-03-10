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
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))

int N, M;

// Graph
struct Edge
{
    int u, v;
    ll w;

    Edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}

    bool operator<(const Edge &o) const
    {
        return w < o.w;
    }
};
vector<Edge> edges;

// DSU
int lab[maxN];

struct DSU
{
    void preprocess()
    {
        fill(lab + 1, lab + N + 1, -1);
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

        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;

        return true;
    }

} dsu;

void input()
{
    cin >> N >> M;

    for (int u, v, w, i = 0; i < M; ++i)
    {
        cin >> u >> v >> w;

        edges.eb(u, v, w);
    }
}

void solve()
{
    ll ans = 0;
    sort(edges.begin(), edges.end());

    for (Edge e : edges)
    {
        if (dsu.join(e.u, e.v))
        {
            ans += e.w;
        }
    }

    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    input();

    dsu.preprocess();

    solve();

    return 0;
}