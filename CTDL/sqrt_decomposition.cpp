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
#define pii pair<int, int>

const int maxN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 2e9;
const ll INFLL = 4e18;
const int LG = 20;
const int BLOCK_SIZE = 320;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))
#define start_of_block(b) ((b) * BLOCK_SIZE + 1)
#define end_of_block(b) min(n, ((b) + 1) * BLOCK_SIZE)
#define block(i) (((i) - 1) / BLOCK_SIZE)

// Mo's Algorithm
struct query
{
    int l, r;
    int id;

    query(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}

    bool operator<(const query &o) const
    {
        if (block(l) == block(o.l))
        {
            return (block(l) & 1 ? r < o.r : r > o.r);
        }
        
        return l < o.l;
    }
};

vector<query> Queries;

void add(int i)
{
    
}

void rem(int i)
{
    
}

void solve()
{
    // Input Queries

    sort(Queries.begin(), Queries.end());

    int L = 1, R = 0;
    for (query qr : Queries)
    {
        while (L > qr.l)
            add(--L);
        while (L < qr.l)
            rem(L++);
        while (R > qr.r)
            rem(R--);
        while (R < qr.r)
            add(++R);

        // ans[qr.id] = ...
    }

    // for (int i = 0; i < q; ++i)
    // {
    //     cout << ans[i] << el;
    // }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    // Input
    // Solve

    return 0;
}