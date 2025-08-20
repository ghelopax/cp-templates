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

// Trie
struct Trie
{
    struct Node
    {
        Node *child[26];
    };

    Node *root;

    Trie()
    {
        root = new Node();
    }

    void add(string s)
    {
        Node *p = root;

        for (char c : s)
        {
            int _c = c - 'a';
            Node *&chi = p->child[_c];

            if (chi == nullptr)
                chi = new Node();

            p = chi;
        }
    }
};

// Trie nhị phân
struct Binary_Trie
{
    struct Node
    {
        Node *child[2];
        ll value;
    };

    Node *root;

    Binary_Trie()
    {
        root = new Node();
    }

    void add(ll __val)
    {
        Node *p = root;

        for (int i = 63; i >= 0; --i)
        {
            bool bit = (__val >> i) & 1LL;
            Node *&chi = p->child[bit];

            if (chi == nullptr)
                chi = new Node();

            p = chi;
        }

        p->value = __val;
    }

    ll max_xor(ll __val)
    {
        Node *p = root;

        for (int i = 63; i >= 0; --i)
        {
            bool bit = (__val >> i) & 1LL;

            Node *xorchi = p->child[!bit];
            Node *chi = p->child[bit];

            p = (xorchi == nullptr ? chi : xorchi);
        }

        return p->value;
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
