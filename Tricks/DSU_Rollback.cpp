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

    Edge(int _u, int _v) 
    {
        if (_u > _v) swap(_u, _v);
        u = _u; v = _v;
    }

    bool operator<(const Edge &o) const
    {
        return tie(u, v) < tie(o.u, o.v);
    }
};

int n, m, k;
vector<Edge> GE;

void input()
{
    cin >> n >> m >> k;

    FOR(id, 0, m - 1)
    {
        int u, v;
        cin >> u >> v;

        GE.eb(u, v);
    }
}

namespace Subtask_1
{
    bool constraint()
    {
        return true;
    }

    // Segment Tree on time
    struct Segment_Tree
    {
        vector<Edge> ST[4 * maxN];

        void update(int id, int l, int r, int u, int v, Edge e)
        {
            if (r < u || v < l) return;
            if (u <= l && r <= v)
            {
                ST[id].pb(e);
                return;
            }

            int mid = MID(l, r);
            update(id << 1, l, mid, u, v, e);
            update(id << 1 | 1, mid + 1, r, u, v, e);
        }
    };

    // DSU Rollback
    struct DSU
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
        int old_sz;

        void init(int _N)
        {
            memset(lab, -1, sizeof(lab));
            cnt = _N;
            old_sz = 0;
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
            Action act = history.top(); history.pop();

            lab[lab[act.node]] -= act.old_lab;
            lab[act.node] = act.old_lab;
            ++cnt;
        }

        void snapshot() { old_sz = isz(history); }
        void restore() { while (isz(history) > old_sz) rollback(); }
    };

    int ans[maxN];

    struct Manager
    {
        DSU dsu;
        Segment_Tree st;
        map<Edge, int> last;

        void init()
        {
            dsu.init(n);

            FOR(id, 0, m - 1)
                last[GE[id]] = 0;
        }

        void update(int l, int r, Edge e) { st.update(1, 0, k, l, r, e); }

        void dfs(int id, int l, int r)
        {
            dsu.snapshot();

            for (Edge &e : st.ST[id])
                dsu.join(e.u, e.v);

            if (l != r)
            {
                int mid = MID(l, r);
                dfs(id << 1, l, mid);
                dfs(id << 1 | 1, mid + 1, r);
            }
            else ans[l] = dsu.cnt;

            dsu.restore();
        }
    } mng;

    void preprocess()
    {
        mng.init();
    }

    void getQuery(int id)
    {
        char type; cin >> type;

        if (type == '1')
        {
            int a, b;
            cin >> a >> b;

            mng.last[Edge(a, b)] = id;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            
            Edge e(a, b);

            // cerr << "lifespan: " << a << ' ' << b << ": " << mng.last[e] << '-' << id - 1 << el;
            mng.update(mng.last[e], id - 1, e);
            mng.last.erase(e);
        }
    }

    void processQuery()
    {
        FOR(id, 1, k) getQuery(id);
        for (auto &x : mng.last)
        {
            // cerr << "lifespan: " << x.first.u << ' ' << x.first.v << ": " << x.second << '-' << k << el;
            mng.update(x.second, k, x.first);
        }
    }

    void solve()
    {
        mng.dfs(1, 0, k);
    }   

    void run()
    {
        preprocess();
        processQuery();
        solve();
        FOR(t, 0, k) cout << ans[t] << ' ';
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