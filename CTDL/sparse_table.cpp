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
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll INFLL = 4e18;
const int LG = 20;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))

// Sparse Table
int st[LG + 1][maxN];

struct Sparse_Table
{
    int *pArr;
    int N;

    Sparse_Table(int *p, int _N) : pArr(p), N(_N) {}

    void build()
    {
        for (int i = 1; i <= N; ++i)
        {
            st[0][i] = pArr[i];
        }

        for (int j = 1; j <= LG; ++j)
        {
            for (int i = 1; i + (1 << j) - 1 <= N; ++i)
            {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int get(int l, int r)
    {
        int lglen = __lg(r - l + 1);

        return min(st[lglen][l], st[lglen][r - (1 << lglen) + 1]);
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    return 0;
}
