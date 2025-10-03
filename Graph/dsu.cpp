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
#define maxN (int)(1e5 + 5)

// Disjoint Set Union
int lab[maxN];

struct DSU
{

    DSU(int _n = 1)
    {
        fill(lab + 1, lab + _n + 1, -1);
    }

    int find(int u)
    {
        return (lab[u] < 0 ? u : lab[u] = find(lab[u]));
    }

    void join(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v)
            return;

        if (lab[u] < lab[v])
            swap(u, v);

        lab[v] += lab[u];
        lab[u] = v;
    }
};

signed main()
{

        return 0;
}
