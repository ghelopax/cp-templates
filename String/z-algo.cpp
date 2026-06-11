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

string s;

void input()
{
    cin >> s;
}

namespace Subtask_1
{
    bool constraint()
    {
        return true;
    }

    vector<int> ZFunc(const string &str)
    {
        int sz = str.size();
        vector<int> z(sz, 0);

        int l = 0, r = 0;
        FOR(i, 1, sz - 1)
        {
            if (i <= r) z[i] = min(z[i - l], r - i + 1);
            for (; i + z[i] < sz && str[i + z[i]] == str[z[i]]; ++z[i]);
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }

        return z;
    }

    vector<int> z;

    void preprocess()
    {
        z = ZFunc(s);
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