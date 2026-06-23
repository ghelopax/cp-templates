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

struct DSU
{
    int lab[maxN];

    void init()
    {
        memset(lab, -1, sizeof(lab));
    }

    int find(int u)
    {
        return (lab[u] < 0 ? u : lab[u] = find(lab[u]));
    }

    bool join(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v) return false;

        if (lab[u] > lab[v]) swap(u, v);

        lab[u] += lab[v];
        lab[v] = u;

        return true;
    }
};

// DSU Rollback
struct RB_DSU
{
    private:
    int lab[maxN];

    struct Action
    {
        int node, old_lab;

        Action() {}
        Action(int _node, int _old_lab) : node(_node), old_lab(_old_lab) {}
    };

    public:
    int cnt;
    stack<Action> history;

    void init(int _N)
    {
        memset(lab, -1, sizeof(lab));
        cnt = _N;
    }

    int findRoot(int u)
    {
        while (lab[u] > 0) u = lab[u];
        return u;
    }

    bool join(int u, int v)
    {
        u = findRoot(u), v = findRoot(v);

        if (u == v) return false;

        if (lab[u] > lab[v]) swap(u, v);

        history.emplace(v, lab[v]);
        lab[u] += lab[v];
        lab[v] = u;
        --cnt;

        return true;
    }

    void rollback()
    {
        Action lastAct = history.top(); history.pop();

        lab[lab[lastAct.node]] -= lastAct.old_lab;
        lab[lastAct.node] = lastAct.old_lab;
        ++cnt;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    

    return 0;
}