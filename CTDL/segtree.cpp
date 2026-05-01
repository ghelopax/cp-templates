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
const ll MOD = 1e9 + 7;
const int INF = 1e9;
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
ll A[maxN];

// Segment Tree
struct Segment_Tree
{
    private:
    ll *pArr;
    ll ST[4 * maxN];
    ll LZ[4 * maxN];

    void down(int id, int l, int r)
    {
        if (!LZ[id]) return;

        ST[id << 1] += LZ[id];
        ST[id << 1 | 1] += LZ[id];

        LZ[id << 1] += LZ[id];
        LZ[id << 1 | 1] += LZ[id];

        LZ[id] = 0;
    }

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            ST[id] = pArr[l];
            return;
        }

        int mid = MID(l, r);

        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);

        ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
    }

    void update(int id, int l, int r, int u, int v, ll w)
    {
        if (r < u || v < l)
            return;

        if (u <= l && r <= v)
        {
            ST[id] += w;
            LZ[id] += w;
            return;
        }

        down(id, l, r);

        int mid = MID(l, r);

        update(id << 1, l, mid, u, v, w);
        update(id << 1 | 1, mid + 1, r, u, v, w);

        ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
    }

    ll get(int id, int l, int r, int u, int v)
    {
        if (r < u || v < l)
            return INFLL;
        
        if (u <= l && r <= v)
            return ST[id];

        down(id, l, r);

        int mid = MID(l, r);

        return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

    // Max Segtree
    // int lwb(int id, int l, int r, ll w)
    // {
    //     if (ST[id] < w)
    //         return -1;
    //     if (l == r)
    //         return l;

    //     int mid = MID(l, r);

    //     if (ST[id << 1] >= w)
    //         return lwb(id << 1, l, mid, w);
    //     else
    //         return lwb(id << 1 | 1, mid + 1, r, w);
    // }

    public:
    Segment_Tree(ll *_pArr) : pArr(_pArr) {}

    void build()
    {
        build(1, 1, N);
    }

    void update(int l, int r, ll w)
    {
        update(1, 1, N, l, r, w);
    }

    ll get(int l, int r)
    {
        return get(1, 1, N, l, r);
    }
};

Segment_Tree st(A);

signed main()
{
    // input();
    st.build();

    return 0;
}
