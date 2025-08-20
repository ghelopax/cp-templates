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

// Tree Diameter
pair<int, int> dmax(vector<int> *_adj, int _N, int s)
{
    pair<int, int> res = {-1, 0};

    vector<bool> _vst(_N, false);
    queue<pair<int, int>> q;

    _vst[s] = true;
    q.emplace(s, 0);

    while (!q.empty())
    {
        int u, du;
        tie(u, du) = q.front();
        q.pop();

        if (res.second < du)
        {
            res = {u, du};
        }

        for (int v : _adj[u])
        {
            if (!_vst[v])
            {
                _vst[v] = true;

                q.emplace(v, du + 1);
            }
        }
    }

    return res;
}

int diameter(vector<int> *_adj, int _N, int root)
{
    int A = dmax(_adj, _N, root).first;

    if (A == -1)
        return 0;

    int B, res;
    tie(B, res) = dmax(_adj, _N, A);

    return res;
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
