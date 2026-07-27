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

const int maxN = 5e4 + 5;
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

struct Node
{
    int id;

    Node(int _id) : id(_id) {}
};

struct Nxt
{
    Node to;
    int w;
};
vector<Nxt> adj[maxN];
int S;

void input()
{
    // cin ...
}

namespace Subtask_1
{
    const int maxW = 1e2;

    bool constraint()
    {
        return true;
    }

    /*
        Bucket Implementation of Dijkstra's Algorithm in general problems.
        (Dial's Algorithm)
        O(E + W*V)
    */
    bool fxd[maxN];
    bool &fixed(const Node &u) { return fxd[u.id]; }
    ll c[maxN];
    ll &cost(const Node &u) { return c[u.id]; }

    struct Bucket
    {
        queue<Node> q[maxW + 5];
        int ptr;
        int size;

        Bucket() : ptr(0), size(0) {}

        void push(Node u, ll c)
        {
            q[c % (maxW + 1)].push(u);
            ++size;
        }

        Node front()
        {
            while (q[ptr].empty()) ptr = (ptr == maxW ? 0 : ptr + 1);
            return q[ptr].front();
        }

        void pop()
        {
            q[ptr].pop();
            --size;
        }
    } bucket;

    void relax(const Node &u, const Nxt &nxt)
    {
        if (cost(nxt.to) > cost(u) + nxt.w)
        {
            cost(nxt.to) = cost(u) + nxt.w;
            bucket.push(nxt.to, cost(nxt.to));
        }
    }

    void dijkstra(Node src)
    {
        memset(c, 0x3f, sizeof(c));
        memset(fixed, 0, sizeof(fixed));
        cost(src) = 0;

        bucket.push(src, cost(src));
        while (bucket.size)
        {
            Node u = bucket.front(); bucket.pop();
            if (fixed(u)) continue; fixed(u) = true;
            for (const Nxt &nxt : adj[u.id]) relax(u, nxt);
        }
    }

    void preprocess()
    {
    }

    void solve() // or: void query()
    {
        dijkstra(Node(S));
        // cout << cost(Node(T));
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