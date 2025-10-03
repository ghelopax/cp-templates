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

#define int long long
#define el "\n"
#define INF LLONG_MAX
#define maxN (int)(1e5 + 5)
#define MID(l, r) ((l) + (((r) - (l)) >> 1))

// Segment_Tree
int ST[4 * maxN];

struct Segment_Tree
{
    int *pArr;

    Segment_Tree(int *p) : pArr(p) {}

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            ST[id] = pArr[l];
            return;
        }

        int mid = MID(l, r);

        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);

        // Merge
        ST[id] = ST[2 * id] + ST[2 * id + 1];
    }

    void update(int id, int l, int r, int idx, int val)
    {
        if (r < idx || idx < l)
            return;
        if (l == r)
        {
            ST[id] = val;
            return;
        }

        int mid = MID(l, r);

        update(2 * id, l, mid, idx, val);
        update(2 * id + 1, mid + 1, r, idx, val);

        // Merge
        ST[id] = ST[2 * id] + ST[2 * id + 1];
    }

    int get(int id, int l, int r, int lhs, int rhs)
    {
        if (r < lhs || rhs < l)
            return 0; // Identity
        if (lhs <= l && r <= rhs)
            return ST[id];

        int mid = MID(l, r);

        int get1 = get(2 * id, l, mid, lhs, rhs);
        int get2 = get(2 * id + 1, mid + 1, r, lhs, rhs);

        // Merge
        return get1 + get2;
    }
};

signed main()
{

    return 0;
}
