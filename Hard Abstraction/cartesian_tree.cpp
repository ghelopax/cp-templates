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

const int maxN = 2e3 + 5;
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

void minimize(ll &x, ll w)
{
    if (x > w)
    {
        x = w;
        // cerr << x << el;
    }
}

int n;
ll r;
ll a[maxN];

void input()
{
    cin >> n >> r;

    FOR(i, 1, n) cin >> a[i];
}

namespace Subtask_1
{
    bool constraint()
    {
        return true;
    }

    // dp[u][k] := cần ít nhất bao nhiêu thao tác để làm rỗng k đỉnh trong cây con gốc u?
    ll dp[maxN][maxN];

    struct Cartesian_Tree
    {
        int root;
        int lf[maxN], rg[maxN];
        int child(int u, bool c) { return (c ? rg[u] : lf[u]); }

        int sz[maxN];
        ll delta[maxN];

        void init()
        {
            root = 0;
            stack<int> st;
            FOR(i, 1, n)
            {
                while (!st.empty() && a[st.top()] >= a[i]) st.pop();

                if (st.empty()) 
                    lf[i] = root, root = i;
                else
                    lf[i] = rg[st.top()], rg[st.top()] = i;
                
                st.push(i);
            }
        }

        void calc(int u)
        {
            sz[u] = 1;
            FOR(c, 0, 1)
            {
                int v = child(u, c); if (!v) continue;
                delta[v] = a[v] - a[u];
                calc(v);
                sz[u] += sz[v];
            }
        }

        void dfs(int u)
        {
            int L = lf[u], R = rg[u];
            if (L) dfs(L);
            if (R) dfs(R);

            dp[u][0] = 0;
            FOR(i, 0, sz[L])
                FOR(j, 0, sz[R])
                    minimize(dp[u][i + j + 1], dp[L][i] + dp[R][j] + delta[u]);
        }
    } ct;

    void preprocess()
    {
        ct.init();
        ct.delta[ct.root] = a[ct.root];
        ct.calc(ct.root);
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
    }

    signed solve() // or: void query()
    {
        ct.dfs(ct.root);
        
        // FOR(i, 0, n)
        //     cerr << dp[ct.root][i] << el;

        for (int k = n; k > 0; --k)
            if (dp[ct.root][k] <= r)
                return cout << k, 0;
        return cout << 0, 0;
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