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
#define BIT(msk, i) (((msk) >> (i)) & 1LL)
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))
#define FOR(i, l, r) for (int i = (l); i <= (int)(r); ++i)
#define FORLL(i, l, r) for (ll i = (l); i <= (ll)(r); ++i)



void input()
{
}

namespace Subtask_1
{
    bool constraint()
    {
        return true;
    }

    struct Trie
    {
        struct Node
        {
            int nxt[26];
            vector<int> ids;
        } T[maxN];

        int cur;

        int newNode()
        {
            ++cur;
            memset(T[cur].nxt, -1, sizeof(T[cur].nxt));
            T[cur].ids.clear();
            return cur;
        }

        Trie() : cur(0)
        {
            memset(T[0].nxt, -1, sizeof(T[0].nxt));
            T[0].ids.clear();
        }

        void insert(int id, const string &str)
        {
            int u = 0;
            for (char ch : str)
            {
                int c = ch - 'A';
                if (T[u].nxt[c] == -1)
                    T[u].nxt[c] = newNode();
                
                u = T[u].nxt[c];
            }

            T[u].ids.pb(id);
        }
    };

    struct Aho_Corasick
    {
        Trie trie;
        int fail[maxN];
        int aut[maxN][26];
        int exit[maxN];

        void insert(int id, const string &pattern) { trie.insert(id, pattern); }

        void build()
        {
            queue<int> q;

            fail[0] = 0;
            exit[0] = 0;
            FOR(c, 0, 25)
            {
                int v = trie.T[0].nxt[c];
                if (v == -1) aut[0][c] = 0;
                else
                {
                    aut[0][c] = v;
                    fail[v] = 0;
                    exit[v] = 0;
                    q.push(v);
                }
            }

            while (!q.empty())
            {
                int u = q.front(); q.pop();

                FOR(c, 0, 25)
                {
                    int v = trie.T[u].nxt[c];
                    if (v == -1) aut[u][c] = aut[fail[u]][c];
                    else
                    {
                        aut[u][c] = v;
                        fail[v] = aut[fail[u]][c];
                        exit[v] = (trie.T[fail[v]].ids.empty() ? exit[fail[v]] : fail[v]);
                        q.push(v);
                    }
                }
            }
        }
    };

    void preprocess()
    {
    }

    void solve() // or: void query()
    {
        
    }

    void run()
    {
        preprocess();
        solve(); // or: while(Q--) query();
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    input();

    if (Subtask_1::constraint()) return Subtask_1::run(), 0;

    return 0;
}