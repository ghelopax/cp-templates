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
    OJ.UZ
    COCI 2025/2026 Contest #4 Magija
*/

#define ll long long
#define ldb long double
#define pii pair<int, int>

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

int N, Q;

void input()
{
    cin >> N >> Q;
}

namespace Subtask_3
{
    const int maxN = 1e3 + 5;

    bool constraint()
    {
        return N <= 1e3 && Q <= 1e3;
    }

    struct DSU
    {
        int lab[maxN];
        int lf[maxN];
        int rg[maxN];

        void init(int _N)
        {
            FOR(i, 1, N) lab[i] = -1, lf[i] = rg[i] = i;
        }

        int find(int u)
        {
            return (lab[u] < 0 ? u : lab[u] = find(lab[u]));
        }

        bool join(int u, int v)
        {
            int add[2] = {u, v};
            u = find(u), v = find(v);

            if (u == v) return false;

            if (lab[u] < lab[v]) swap(u, v);

            lab[u] += lab[v];
            lab[v] = u;
            lf[u] = min(lf[u], lf[v]);
            rg[u] = max(rg[u], rg[v]);

            // cerr << u << ": " << add[0] << ' ' << add[1] << ' ' << lf[u] << el;
            lf[u] = min({add[0], add[1], lf[u]});
            rg[u] = max({add[0], add[1], rg[u]});

            return true;
        }
    } dsu;

    void preprocess()
    {
        dsu.init(N);
    }

    void query()
    {
        char type; cin >> type;

        if (type == '1')
        {
            int x; cin >> x;

            int r = dsu.find(x);

            cout << dsu.lf[r] << ' ' << dsu.rg[r] << el;
        }
        else
        {
            int l, r, len;
            cin >> l >> r >> len;

            FOR(i, 0, len - 1)
            {
                dsu.join(l + i, r + i);
            }
        }
    }

    void run()
    {
        preprocess();
        while(Q--) query();
    }
}

namespace Subtask_6
{
    const int maxN = 2e5 + 5;

    bool constraint()
    {
        return true;
    }

    struct DSU
    {
        int lab[maxN];
        int lf[maxN];
        int rg[maxN];

        void init()
        {
            memset(lab, -1, sizeof(lab));
            FOR(i, 1, N) lf[i] = rg[i] = i;
        }

        int find(int u)
        {
            return (lab[u] < 0 ? u : lab[u] = find(lab[u]));
        }

        bool join(int u, int v)
        {
            int add[2] = {u, v};
            u = find(u), v = find(v);

            if (u == v) return false;

            if (lab[u] < lab[v]) swap(u, v);

            lab[u] += lab[v];
            lab[v] = u;
            lf[u] = min(lf[u], lf[v]);
            rg[u] = max(rg[u], rg[v]);

            // cerr << u << ": " << add[0] << ' ' << add[1] << ' ' << lf[u] << el;
            lf[u] = min({add[0], add[1], lf[u]});
            rg[u] = max({add[0], add[1], rg[u]});

            return true;
        }

        bool connected(int u, int v)
        {
            return find(u) == find(v);
        }
    };

    struct Sparse_Table
    {
        DSU dsu[LG + 1];

        void init()
        {
            FOR(k, 0, LG) dsu[k].init();
        }

        void update(int u, int v, int k)
        {
            if (dsu[k].connected(u, v)) return;

            dsu[k].join(u, v);
            if (k > 0) 
            {
                update(u, v, k - 1);
                update(u + MASK(k - 1), v + MASK(k - 1), k - 1);
            }
        }

        pair<int, int> query(int x)
        {
            x = dsu[0].find(x);
            return make_pair(dsu[0].lf[x], dsu[0].rg[x]);
        }

        void query(int l, int r, int len)
        {
            int i = 0;
            for (int k = LG; k >= 0; --k)
            {
                if (BIT(len, k))
                {
                    update(l + i, r + i, k);
                    i += MASK(k);
                }
            }
        }
    } st;

    void preprocess()
    {
        st.init();   
    }

    void query()
    {
        char type; cin >> type;

        if (type == '1')
        {
            int x; cin >> x;

            pii res = st.query(x);

            cout << res.first << ' ' << res.second << el;
        }
        else
        {
            int l, r, len;
            cin >> l >> r >> len;

            st.query(l, r, len);
        }
    }

    void run()
    {
        preprocess();
        while(Q--) query();
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

    if (Subtask_3::constraint()) return Subtask_3::run(), 0;
    if (Subtask_6::constraint()) return Subtask_6::run(), 0;

    return 0;
}