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
#define isz(v) (int)v.size()

int N;
ll a[maxN];
int Q;

void input()
{
    cin >> N;

    FOR(i, 1, N) cin >> a[i];

    cin >> Q;
}

namespace Subtask_4
{
    bool constraint()
    {
        return true;
    }

    int fail[maxN];
    ll g[maxN];
    ll preg[maxN];

    ll ans;

    int up[maxN][LG + 1];

    void preprocess()
    {
        a[0] = 0;

        fail[0] = 0;
        g[0] = 0; preg[0] = 0;
        FOR(i, 1, N)
        {
            int j = i - 1;
            while (j != 0 && a[j] >= a[i]) j = fail[j];
            fail[i] = j;

            up[i][0] = j;
            FOR(k, 1, LG) up[i][k] = up[up[i][k - 1]][k - 1];

            g[i] = (g[j] + (a[i] * (i - j)) % MOD) % MOD;
            preg[i] = (preg[i - 1] + g[i]) % MOD;
        }

        ans = preg[N];
    }

    void query()
    {
        int p;
        ll v;
        cin >> p >> v;
        ++p;

        int j = p - 1;
        if (j != 0 && a[j] >= v)
        {
            for (int k = LG; k >= 0; --k)
                if (a[up[j][k]] >= v)
                    j = up[j][k];
            
            j = fail[j];
        }

        ans += (preg[p - 1] + (g[j] + (v * (p - j)) % MOD) % MOD) % MOD;
        ans %= MOD;
    }

    void run()
    {
        preprocess();
        while(Q--) query();
        cout << ans;
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

    if (Subtask_4::constraint()) return Subtask_4::run(), 0;

    return 0;
}