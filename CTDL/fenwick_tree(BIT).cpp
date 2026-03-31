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
#define lsb(x) ((x) & -(x))

// Input
int N;

// Fenwick Tree
ll bit[maxN];

struct Fenwick_Tree
{
    ll get(int i)
    {
        ll res = 0;

        for (int idx = i; idx > 0; idx -= lsb(idx))
            res += bit[idx];
        
        return res;
    }

    void update(int i, ll w)
    {
        for (int idx = i; idx <= N; idx += lsb(idx))
            bit[idx] += w;
    }

    int kth(int k) // Binary Lifting
    {
        int pos = 0;
        ll sum = 0;
        for (int idx = LG; idx >= 0; --idx)
        {
            int nxt = pos + (1 << idx);
            if (nxt >= maxN) continue;

            if (sum + bit[nxt] < k) 
            {
                pos = nxt;
                sum += bit[nxt];
            }
        }

        return pos + 1;
    }
};

ll bitd[maxN]; // BIT of difference array d[i] = a[i] - a[i - 1]
ll bitg[maxN]; // BIT of g[i] = (i - 1) * d[i]

struct RangeFT
{
    ll get(int i)
    {
        ll res = 0;

        for (int idx = i; idx > 0; idx -= lsb(idx))
        {
            res += bitd[idx];
        }

        return res;
    }

    ll get_range(int i)
    {
        ll res = 0;

        for (int idx = i; idx > 0; idx -= lsb(idx))
        {
            res += bitd[idx] * i - bitg[idx];
        }

        return res;
    }

    void update(ll *bit, int i, ll w)
    {
        for (int idx = i; idx <= N; idx += lsb(idx))
        {
            bit[idx] += w;
        }
    }

    void update_range(int l, int r, ll w)
    {
        update(bitd, l, w);
        update(bitd, r + 1, -w);
        update(bitg, l, (l - 1) * w);
        update(bitg, r + 1, -r * w);
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
