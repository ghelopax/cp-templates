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
    VNOJ
    VM 09 Bài 06 - Số rõ ràng
*/

#define ll long long
#define ldb long double

const int maxN = 1458;
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

string n;
ll m;

void input()
{
    cin >> n >> m;
}

namespace Subtask_1
{
    bool constraint()
    {
        return true;
    }

    char check[maxN + 5];

    char calc(int x)
    {
        char &memo = check[x];
        if (memo != '#') return memo;
        if (x == 1) return memo = '1';

        check[x] = '-';

        int sum = 0;
        while (x > 0)
        {
            sum += (x % 10) * (x % 10);
            x /= 10;
        }

        char tmp = calc(sum);
        if (tmp == '-' || tmp == '0') return memo = '0';
        return memo = '1';
    }

    // Lexicographic DP
    const int SZ = 18;
    struct Lexicographic
    {
        struct State
        {
            int sum;

            State() : sum(0) {}
            State(int _sum) : sum(_sum) {}

            bool trans(int dgt)
            {
                sum += dgt * dgt;
                return true;
            }
        };

        ll dp[SZ + 5][maxN];

        void init()
        {
            fill(check + 1, check + maxN + 1, '#');
            FOR(i, 1, maxN) calc(i);
            memset(dp, -1, sizeof(dp));
            count(0, State());
        }

        ll count(int pos, State s)
        {
            ll &memo = dp[pos][s.sum];
            if (memo != -1) return memo;
            if (pos == SZ) return memo = (calc(s.sum) == '1' ? 1 : 0);

            memo = 0;
            FOR(i, 0, 9)
            {
                State ns(s);
                if (!ns.trans(i)) continue;

                memo += count(pos + 1, ns);
            }

            return memo;
        }

        ll rank(string x)
        {
            ll res = 0;

            State s;
            FOR(pos, 0, SZ - 1)
            {
                int dgt = x[pos + 1] - '0';
                FOR(i, 0, dgt - 1)
                {
                    State ns(s); 
                    if (!ns.trans(i)) continue;

                    res += count(pos + 1, ns);
                }
                s.trans(dgt);
            }

            return res;
        }

        string unrank(ll rank)
        {
            string res = "";
            ll cur = rank;

            State s;
            FOR(pos, 0, SZ - 1)
            {
                FOR(i, 0, 9)
                {
                    State ns(s); 
                    if (!ns.trans(i)) continue;

                    if (count(pos + 1, ns) <= cur) cur -= count(pos + 1, ns);
                    else
                    {
                        res += (char)('0' + i);
                        s.trans(i);
                        break;
                    }
                }
            }

            return res;
        }
    } lxc;
   
    void preprocess()
    {
        while (n.size() < SZ) n = "0" + n;
        n = "#" + n;
        
        lxc.init();
    }

    void solve() // or: void query()
    {
        ll sum = 0;
        FOR(i, 1, SZ) sum += (n[i] - '0') * (n[i] - '0');

        ll rank = lxc.rank(n);
        if (calc(sum) == '0') --rank;

        string ans = lxc.unrank(rank + m);

        reverse(ans.begin(), ans.end());
        while (ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());

        cout << ans << el;
    }

    void run()
    {
        preprocess();
        solve(); // or: while(Q--) query();
    }
}

signed ghelopax()
{
    input();

    if (Subtask_1::constraint()) return Subtask_1::run(), 0;

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    int TC; cin >> TC;
    while (TC--) ghelopax();

    return 0;
}