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
#define pli pair<ll, int>

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

struct Nxt
{
    int to;
    ll w;
};
vector<Nxt> adj[maxN];

void input()
{
}

namespace Subtask_1
{
    bool constraint()
    {
    }

    deque<int> dq;
    ll dist[maxN];
    bool fixed[maxN];
    void bfs01(int src)
    {
        memset(dist, 0x7f, sizeof(dist));
        memset(fixed, 0, sizeof(fixed));
        dist[src] = 0;

        dq.push_front(src);

        while (!dq.empty())
        {
            int u = dq.front(); dq.pop_front();

            if (fixed[u]) continue;
            fixed[u] = true;

            for (const Nxt &nxt : adj[u])
            {
                ll cur = dist[u] + nxt.w;
                if (dist[nxt.to] > cur)
                {
                    dist[nxt.to] = cur;
                    if (nxt.w == 1) dq.push_back(nxt.to);
                    else dq.push_front(nxt.to);
                }
            }
        }
    }

    void preprocess()
    {
    }

    void solve() // or: void query()
    {
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

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    input();

    if (Subtask_1::constraint()) return Subtask_1::run(), 0;

    return 0;
}