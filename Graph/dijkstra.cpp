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
    int to;
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
        Dijkstra's Algorithm in general problems
    */
   
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
        Label cur = lab[u.id].apply(nxt);
        if (lab[nxt.to] > cur)
        {
            lab[nxt.to] = cur;
            pq.emplace(Node(nxt.to), cur);
        }
    }

    bool fixed[maxN];
    void dijkstra(Node src)
    {
        fill(lab, lab + maxN, Label(INFLL));
        memset(fixed, 0, sizeof(fixed));
        lab[src.id] = Label(0);
        fixed[src.id] = true;

        pq.emplace(src, lab[src.id]);
        while (!pq.empty())
        {
            State st = pq.top(); pq.pop();

            if (fixed[st.u.id]) continue;
            fixed[st.u.id] = true;

            for (const Nxt &nxt : adj[st.u.id])
                relax(st.u, nxt);
        }
    }

    void preprocess()
    {
    }

    void solve() // or: void query()
    {
        dijkstra(Node(S));
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