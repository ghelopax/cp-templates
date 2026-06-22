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

        int fail[maxN];
        int aut[maxN][26];

        void build()
        {
            // fail[0] = fail[1] = 0;
            // FOR(i, 2, sz)
            // {
            //     int u = fail[i - 1];
            //     for (; u != 0 && str[u + 1] != str[i]; u = fail[u]);
            //     if (u == 0) fail[i] = (str[1] == str[i]); 
            //     else fail[i] = u + 1;
            // }

            fail[0] = fail[1] = 0;
            FOR(c, 0, 25) aut[0][c] = (c == str[1] - 'A');

            FOR(i, 1, sz) FOR(c, 0, 25)
            {
                if (c == str[i + 1] - 'A')
                {
                    aut[i][c] = i + 1;
                    fail[i + 1] = aut[fail[i]][c];
                }
                else aut[i][c] = aut[fail[i]][c];
            }
        }

        void init(const string &pattern)
        {
            sz = pattern.size();
            str = "#" + pattern + "#";

            build();
        }
    };

    KMP kmp;

    void preprocess()
    {
        kmp.init(S);
    }

    void solve() // or: void query()
    {
        
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