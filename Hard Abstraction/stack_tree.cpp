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
    QOJ
    Singapore NOI 2026 Final - Task 4: Gemstones
*/

#define ll long long
#define ldb long double

const int maxN = 1e6 + 5;
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

int n, q;
int c[maxN];

void input()
{
    cin >> n >> q;

    FOR(i, 1, n) cin >> c[i];
}

namespace Subtask_9
{
    bool constraint()
    {
        return true;
    }

    struct Tree
    {
        int sz;
        int *par;
        vector<int> child[maxN];
        int up[maxN][LG + 1];
        int h[maxN];

        void calc(int u)
        {
            for (int v : child[u])
            {
                h[v] = h[u] + 1;

                up[v][0] = u;
                FOR(j, 1, LG)
                    up[v][j] = up[up[v][j - 1]][j - 1];

                calc(v);
            }
        }

        void init(int *_par, int _sz)
        {
            par = _par;
            sz = _sz;
            memset(h, 0, sizeof(h));

            FOR(u, 1, sz)
                if (par[u] != 0)
                    child[par[u]].pb(u);

            calc(1);
        }

        int LCA(int u, int v)
        {
            if (h[u] < h[v]) swap(u, v);
            int k = h[u] - h[v];
            FOR(j, 0, LG)
                if (BIT(k, j))   
                    u = up[u][j];

            if (u == v) return u;

            for (int j = LG; j >= 0; --j)
                if (up[u][j] != up[v][j])     
                    u = up[u][j], v = up[v][j];
            
            return up[u][0];
        }

        int dist(int u, int v)
        {
            return h[u] + h[v] - 2 * h[LCA(u, v)];
        }
    };

    struct Manager
    {
        private:
        map<int, int> nxt[maxN];
        int par[maxN];
        int state[maxN];
        int cur = 1;

        Tree tree;  

        public:
        void build(int *arr)
        {
            memset(par, 0, sizeof(par));
            int u = 1; state[0] = 1;
            stack<int> st;

            FOR(i, 1, n)
            {
                if (!st.empty() && arr[st.top()] == arr[i])
                {
                    st.pop();
                    u = par[u];
                }
                else 
                {
                    st.push(i);
                    if (nxt[u].find(arr[i]) == nxt[u].end()) 
                    {
                        nxt[u][arr[i]] = ++cur;
                        par[cur] = u;
                    }
                    
                    u = nxt[u][arr[i]];
                }

                state[i] = u;
            }

            tree.init(par, cur);
        }

        int query(int l, int r)
        {
            return tree.dist(state[l - 1], state[r]);
        }
    } mng;

    void preprocess()
    {
        mng.build(c);
    }

    void query()
    {
        int l, r; cin >> l >> r;

        cout << mng.query(l, r) << el;
    }

    void run()
    {
        preprocess();
        while(q--) query();
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

    if (Subtask_9::constraint()) return Subtask_9::run(), 0;

    return 0;
}