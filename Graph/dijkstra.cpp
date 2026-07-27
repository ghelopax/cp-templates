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
    bool constraint()
    {
        return true;
    }

    /*
        Dijkstra's Algorithm in general problems.
        O((V + E)*logV)
    */
    bool fxd[maxN];
    bool &fixed(Node u) { return fxd[u.id]; }

    struct Label
    {
        ll c;

        Label(ll _c) : c(_c) {}

        bool operator>(const Label &o) const
        {
            return c > o.c;
        }

        Label apply(const Nxt &nxt) const
        {
            return Label(c + nxt.w);
        }
    } lab[maxN];
    Label &label(Node u) { return lab[u.id]; }

    struct State
    {
        Node u;
        Label label;

        State(Node _u, Label _label) : u(_u), label(_label) {}

        bool operator>(const State &o) const
        {
            return label > o.label;
        }
    };

    priority_queue<State, vector<State>, greater<State>> pq;
    void relax(Node u, const Nxt &nxt)
    {
        Label cur = label(u).apply(nxt);
        if (label(nxt.to) > cur)
        {
            label(nxt.to) = cur;
            pq.emplace(nxt.to, cur);
        }
    }

    void dijkstra(Node src)
    {
        fill(lab, lab + maxN, Label(INFLL));
        memset(fixed, 0, sizeof(fixed));
        label(src) = Label(0);

        pq.emplace(src, label(src));
        while (!pq.empty())
        {
            State st = pq.top(); pq.pop();
            if (fixed(st.u)) continue; fixed(st.u) = true;
            for (const Nxt &nxt : adj[st.u.id]) relax(st.u, nxt);
        }
    }

    void preprocess()
    {
    }

    void solve() // or: void query()
    {
        dijkstra(Node(S));
        // cout << label(Node(T)).c;
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