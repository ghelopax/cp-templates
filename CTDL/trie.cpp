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
        private:
        struct Node
        {
            int nxt[26];

            int exist;
        } TR[maxN];

        int cur;

        int newNode()
        {
            ++cur;
            memset(TR[cur].nxt, -1, sizeof(TR[cur].nxt));
            return cur;
        }

        public:
        Trie() : cur(0)
        {
            memset(TR[0].nxt, -1, sizeof(TR[0].nxt));
            TR[0].exist = 0;
        }

        void insert(const string &str)
        {
            int u = 0;
            for (char ch : str)
            {
                int c = ch - 'a';
                if (TR[u].nxt[c] == -1)
                    TR[u].nxt[c] = newNode();
                
                u = TR[u].nxt[c];
            }

            ++TR[u].exist;
        }
    };

    Trie trie;

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