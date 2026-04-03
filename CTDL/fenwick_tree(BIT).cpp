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
ll bitd[maxN];
ll bitg[maxN];

struct BIT
{
    BIT(ll *_bit) : bit(_bit) {}
    ll *bit;

    void update(int i, ll w)
    {
        for (; i <= N; i += lsb(i)) bit[i] += w;
    }

    ll get(int i)
    {
        ll res = 0; for (; i > 0; i -= lsb(i)) res += bit[i]; return res;
    }
    
    // Binary Lifting
    // Monotonic prefix sum only
    ll lb(ll w) // first pos: sum[1...i] >= w
    {
        int pos = 0;
        ll sum = 0;
        
        for (int idx = LG; idx >= 0; --idx)
        {
            int nxt = pos + (1 << idx);
            if (nxt >= maxN) continue;

            if (sum + bit[nxt] < w) 
            {
                pos = nxt;
                sum += bit[nxt];
            }
        }

        return pos + 1;
    }
} ftd(bitd), ftg(bitg);

void update_range(int l, int r, ll w) // [l...r]: a_i += w
{
    ftd.update(l, w);
    ftg.update(l, w * l);

    if (r + 1 <= N)
    {
        ftd.update(r + 1, -w);
        ftg.update(r + 1, -w * (r + 1));
    }
}

ll get_range(ll i) // [1...i]: sum(a_i)
{
    return (i + 1) * ftd.get(i) - ftg.get(i);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    return 0;
}
