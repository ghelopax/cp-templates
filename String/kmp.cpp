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
#define FOR(i, l, r) for (ll i = (l); i <= (ll)(r); ++i)

string S;

void input()
{
    cin >> S;
}

namespace Subtask_1
{
    bool constraint()
    {
        return true;
    }

    // KMP Automaton
    struct KMP
    {
        int sz;
        string str;

        void init(const string &_str)
        {
            sz = _str.size();
            str = "#" + _str + "#";
        }

        int fail[maxN]; // fail link
        int aut[maxN][26]; // automaton

        void build_fail()
        {
            fail[0] = fail[1] = 0;
            FOR(i, 2, sz)
            {
                int u = fail[i - 1];

                while (u != 0 && str[i] != str[u + 1]) u = fail[u];

                if (u == 0) fail[i] = (str[i] == str[1] ? 1 : 0);
                else fail[i] = u + 1;
            }
        }

        void build_aut()
        {
            FOR(c, 0, 25) aut[0][c] = (c == str[0] ? 1 : 0);
            FOR(i, 0, sz)
                FOR(c, 0, 25)
                    // Depends on problem's alphabet. Default to 26 uppercase letters
                    aut[i][c] = (c == str[i + 1] - 'A' ? i + 1 : aut[fail[i]][c]);
        }
    };

    KMP kmp;

    void preprocess()
    {
        kmp.init(S);
        kmp.build_fail();
        kmp.build_aut();
    }

    void solve() // or: void query()
    { 
        /* 
            ## Example use: Find matchings of Pattern S in Text T
        */
        string T; cin >> T;


        int u = 0; // initial state: empty string
        for (char c : T)
        {
            // Depends on problem's alphabet. Default to 26 uppercase letters
            u = kmp.aut[u][c - 'A']; // automaton transition

            // Exact matching found
            if (u == kmp.sz)
            {
                // do something with the matching...
            }
        }
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