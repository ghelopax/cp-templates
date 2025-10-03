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

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))

// Fenwick Tree
int bit[maxN];

struct BIT
{
    int N;

    BIT(int __N) : N(__N)
    {
        memset(bit, 0, sizeof(bit));
    }

    int get(int __idx)
    {
        int idx = __idx;
        int sum = 0;

        while (idx > 0)
        {
            sum += bit[idx];
            idx -= lsb(idx);
        }

        return sum;
    }

    void update(int __idx, int __val)
    {
        int idx = __idx;

        while (idx <= N)
        {
            bit[idx] += __val;
            idx += lsb(idx);
        }
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
