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

const int maxN = 2e5 + 5;
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
struct BIT
{
    ll bit[maxN];

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
};

struct RangeBIT
{
    private:
    BIT ft, ift;

    void update(int i, ll w)
    {
        ft.update(i, w);
        ift.update(i, i * w);
    }

    ll get(int i)
    {
        return (i + 1) * ft.get(i) - ift.get(i);
    }

    public:
    void update(int l, int r, ll w)
    {
        update(l, w);

        if (r + 1 <= N)
            update(r + 1, -w);
    }

    ll get(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};

// Fenwick Tree 2D
struct BIT2D
{
    ll bit[maxN][maxN];

    void update(int i, int j, ll w)
    {
        for (int idx = i; idx <= N; idx += lsb(idx))
            for (int jdx = j; jdx <= N; jdx += lsb(jdx))
                bit[idx][jdx] += w;
    }

    ll get(int i, int j)
    {
        ll res = 0;
        for (int idx = i; idx > 0; idx -= lsb(idx))
            for (int jdx = j; jdx > 0; jdx -= lsb(jdx))
                res += bit[idx][jdx];
        return res;
    }
};

struct RangeBIT2D
{
    private:
    BIT2D ft, ift, jft, ijft;

    void update(int i, int j, ll w)
    {
        ft.update(i, j, w);
        ift.update(i, j, i * w);
        jft.update(i, j, j * w);
        ijft.update(i, j, i*j * w);
    }

    ll get(int i, int j)
    {
        return (i + 1)*(j + 1) * ft.get(i, j) - (i + 1) * jft.get(i, j) - (j + 1) * ift.get(i, j) + ijft.get(i, j);
    }

    public:
    void update(int x, int y, int u, int v, ll w)
    {
        update(x, y, w);
        update(x, v + 1, -w);
        update(u + 1, y, -w);
        update(u + 1, v + 1, w);
    }

    ll get(int x, int y, int u, int v)
    {
        return get(u, v) - get(u, y - 1) - get(x - 1, v) + get(x - 1, y - 1);
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
