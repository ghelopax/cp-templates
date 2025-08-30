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

void prefunc(int *_pi, const string &str)
{
    int _n = str.size();
    _pi[0] = 0;

    for (int i = 1; i < _n; ++i)
    {
        int j = _pi[i - 1]; // best prefix

        while (j > 0 && str[j] != str[i]) // best fit
        {
            j = _pi[j - 1];
        }

        _pi[i] = j + (str[j] == str[i]);
    }
}

int kmp_match(int *_pi_pattern, const string &pattern, const string &text)
{
    // prefunc on P + '#' + T, calced P + '#'
    int _n = pattern.size();
    int _m = text.size();

    // pi[P...#] := 0
    int j = 0;

    int cnt = 0;

    for (int i = 0; i < _m; ++i)
    {
        while (j > 0 && pattern[j] != text[i]) // best fit
        {
            j = _pi_pattern[j - 1];
        }

        if (pattern[j] == text[i])
            ++j;

        if (j == _n) // match
        {
            ++cnt;
            j = _pi_pattern[j - 1]; // skip '#'
        }
    }

    return cnt;
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
