#include <bits/stdc++.h>
#include <math.h>
#include <iterator>
#include <map>
#include <list>
#include <cmath>
#include <queue>
using namespace std;
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define ll long long
void sor(vector<ll> &x)
{
    sort(x.begin(), x.end());
}

void rev(vector<ll> &x)
{
    reverse(x.begin(), x.end());
}

ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

list<ll> a[5];
void bfs(int src)
{
    queue<int> q;
    bool *vis = new bool[5 + 1]{0};
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int n : a[node])
        {
            if (!vis[n])
            {
                q.push(n);
                vis[n] = true;
            }
        }
    }
}

ll max(ll x, ll y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

ll min(ll x, ll y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

void primeFactors(ll n, vector<ll> &vec)
{

    while (n % 2 == 0)
    {
        vec.push_back(2);
        n = n / 2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            vec.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        vec.push_back(n);
}

ll lcm(ll x, ll y)
{
    return x * y / gcd(x, y);
}

ll g(ll x)
{
    for (ll i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return i;
        }
    }
    return 0;
}

ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                cnt++;

            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}

ll bina(vector<ll> a, ll n, ll m)
{
    ll start = 0, end = n - 1;
    ll c = 0;
    if (m >= a[n - 1])
    {
        return n;
    }
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (m >= a[mid])
        {
            c = mid + 1;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return c;
}
ll binarySearch(pair<ll, ll> arr[], ll l, ll r, ll x)
{
    if (r >= l)
    {
        ll mid = l + (r - l) / 2;
        if (arr[mid].first == x)
            return arr[mid].second;
        if (arr[mid].first > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }

    return 0;
}
void solve()
{

    ll n, x;
    cin >> n >> x;
    pair<ll, ll> a[n];
    fo(i, n)
    {
        ll q;
        cin >> q;
        a[i] = make_pair(q, i + 1);
    }
    sort(a, a + n);
    fo(i, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll target = x - a[i].first - a[j].first;
            ll start = j + 1, end = n - 1;
            while (start < end)
            {
                if (a[start].first + a[end].first == target)
                {
                    cout << a[i].second << " " << a[j].second << " " << a[start].second << " " << a[end].second;
                    return;
                }
                else if (a[start].first + a[end].first > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t = 1;
    for (ll jj = 0; jj < t; jj++)
    {
        solve();
    }

    return 0;
}

//0 3 1 0 5 2 6
//0 0 1 2 3 5 6