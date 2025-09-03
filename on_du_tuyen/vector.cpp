#include <bits/stdc++.h>
#define task "vector"
#define __Thien_dep_trai__ signed main()
#define ll long long
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int maxn = 3000;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x * y) % mod;
}
ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}

std::vector<int> adj[maxn + 7];
int m, n;
int a[maxn + 7], b[maxn + 7];
bool vis[maxn + 7][maxn + 7];
int pa[maxn + 7][maxn + 7], pb[maxn + 7][maxn + 7], pp[maxn + 7][maxn + 7];
char trace[maxn + 7][maxn + 7];
ll A = 1, B = 1;
std::unordered_map<int, int> va, vb;
vi v;

std::vector<int> divi(int x)
{
    vi d;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            d.push_back(i);
            if (i != x / i)
            {
                d.push_back(x / i);
            }
        }
    }
    std::sort(d.begin(), d.end());
    return d;
}

void sub1()
{
    for (int i = 0; i <= 25; i++)
    {
        for (int j = 0; j <= 25; j++)
        {
            vis[i][j] = false;
            pa[i][j] = pb[i][j] = pp[i][j] = -1;
            trace[i][j] = '?';
        }
    }

    std::queue<ii> q;
    vis[A][B] = true;
    q.push({A, B});
    int ansa = A, ansb = B, ans = A + B;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        int sum = x + y;
        if (sum < ans)
        {
            ans = sum;
            ansa = x;
            ansb = y;
        }

        vi v;
        vi da = divi(x);
        vi db = divi(y);
        for (int i : da)
        {
            if (i > 1)
            {
                v.pb(i);
            }
        }
        for (int i : db)
        {
            if (i > 1)
            {
                v.pb(i);
            }
        }

        for (int p : v)
        {
            int P = p * p;
            if (P <= y && y % P == 0)
            {
                int na = x * p;
                int nb = y / P;
                if (na > 0 && nb > 0 && na <= 25 && nb <= 25 && !vis[na][nb])
                {
                    vis[na][nb] = true;
                    pa[na][nb] = x;
                    pb[na][nb] = y;
                    pp[na][nb] = p;
                    trace[na][nb] = 'W';
                    q.push({na, nb});
                }
            }

            if (P <= x && x % P == 0)
            {
                int na = x / P;
                int nb = y;
                if (na > 0 && nb > 0 && na <= 25 && nb <= 25 && !vis[na][nb])
                {
                    vis[na][nb] = true;
                    pa[na][nb] = x;
                    pb[na][nb] = y;
                    pp[na][nb] = p;
                    trace[na][nb] = 'L';
                    q.push({na, nb});
                }
            }

            int na = x;
            int nb = 1LL * y * p;
            if (nb > 0 && nb <= 25)
            {
                if (!vis[na][nb])
                {
                    vis[na][nb] = true;
                    pa[na][nb] = x;
                    pb[na][nb] = y;
                    pp[na][nb] = p;
                    trace[na][nb] = 'D';
                    q.push({na, nb});
                }
            }
        }
    }

    std::vector<std::pair<int, char>> res;

    int tmpa = ansa, tmpb = ansb;
    while (tmpa != A || tmpb != B)
    {
        int p = pp[tmpa][tmpb];
        char c = trace[tmpa][tmpb];
        res.pb({p, c});
        int para = pa[tmpa][tmpb];
        int parb = pb[tmpa][tmpb];
        tmpa = para;
        tmpb = parb;
    }
    std::reverse(res.begin(), res.end());

    std::cout << res.size() << '\n';
    for (auto i : res)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

void sub3()
{
    for (int i = 1; i <= m; i++)
    {
        A *= a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        B *= b[j];
    }
    for (int i = 0; i <= maxn; i++)
    {
        for (int j = 0; j <= maxn; j++)
        {
            vis[i][j] = false;
            pa[i][j] = pb[i][j] = pp[i][j] = -1;
            trace[i][j] = '?';
        }
    }

    std::queue<ii> q;
    vis[A][B] = true;
    q.push({A, B});
    int ansa = A, ansb = B, ans = A + B;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        int sum = x + y;
        if (sum < ans)
        {
            ans = sum;
            ansa = x;
            ansb = y;
        }

        vi v;
        vi da = divi(x);
        vi db = divi(y);
        for (int i : da)
        {
            if (i > 1)
            {
                v.pb(i);
            }
        }
        for (int i : db)
        {
            if (i > 1)
            {
                v.pb(i);
            }
        }

        for (int p : v)
        {
            int P = p * p;
            if (P <= y && y % P == 0)
            {
                int na = x * p;
                int nb = y / P;
                if (na > 0 && nb > 0 && na <= maxn && nb <= maxn && !vis[na][nb])
                {
                    vis[na][nb] = true;
                    pa[na][nb] = x;
                    pb[na][nb] = y;
                    pp[na][nb] = p;
                    trace[na][nb] = 'W';
                    q.push({na, nb});
                }
            }

            if (P <= x && x % P == 0)
            {
                int na = x / P;
                int nb = y;
                if (na > 0 && nb > 0 && na <= maxn && nb <= maxn && !vis[na][nb])
                {
                    vis[na][nb] = true;
                    pa[na][nb] = x;
                    pb[na][nb] = y;
                    pp[na][nb] = p;
                    trace[na][nb] = 'L';
                    q.push({na, nb});
                }
            }

            int na = x;
            int nb = 1LL * y * p;
            if (nb > 0 && nb <= maxn)
            {
                if (!vis[na][nb])
                {
                    vis[na][nb] = true;
                    pa[na][nb] = x;
                    pb[na][nb] = y;
                    pp[na][nb] = p;
                    trace[na][nb] = 'D';
                    q.push({na, nb});
                }
            }
        }
    }

    std::vector<std::pair<int, char>> res;

    int tmpa = ansa, tmpb = ansb;
    while (tmpa != A || tmpb != B)
    {
        int p = pp[tmpa][tmpb];
        char c = trace[tmpa][tmpb];
        res.pb({p, c});
        int para = pa[tmpa][tmpb];
        int parb = pb[tmpa][tmpb];
        tmpa = para;
        tmpb = parb;
    }
    std::reverse(res.begin(), res.end());

    std::cout << res.size() << '\n';
    for (auto i : res)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

const int mx = 1e5;
bool isprime[mx + 7];
std::vector<int> primes;

void sieve()
{
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= mx; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            if (i * i <= mx)
            {
                for (int j = i * i; j <= mx; j += i)
                {
                    isprime[j] = 0;
                }
            }
        }
    }
}

bool check_sub2 = true;

const int mx = 1e5;
bool isprime[mx + 7];
std::vector<int> primes;

void sieve()
{
    for (int i = 0; i <= mx; ++i)
        isprime[i] = true;
    isprime[0] = isprime[1] = false;

    for (int i = 2; i <= mx; ++i)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            if (1LL * i * i <= mx)
            {
                for (int j = i * i; j <= mx; j += i)
                {
                    isprime[j] = false;
                }
            }
        }
    }
}

void sub2()
{
    std::vector<std::pair<int, char>> res;

    bool check = true;
    while (check)
    {
        check = false;
        for (int p : v)
        {
            int x = va[p];
            int y = vb[p];

            while (x >= 2)
            {
                x -= 2;
                res.push_back({p, 'L'});
                check = true;
                if (res.size() > 1000000)
                {
                    break;
                }
                check_sub2 = false;
            }
            if (res.size() > 1000000)
            {
                break;
            }

            while (y >= 2)
            {
                y -= 2;
                check_sub2 = false;
                x += 1;
                res.push_back({p, 'W'});
                check = true;
                while (x >= 2)
                {
                    x -= 2;
                    res.push_back({p, 'L'});
                    if (res.size() > 1000000)
                    {
                        break;
                    }
                }
                if (res.size() > 1000000)
                {
                    break;
                }
            }
            if (res.size() > 1000000)
            {
                break;
            }
        }
        if (res.size() > 1000000)
        {
            break;
        }
    }

    std::cout << res.size() << "\n";
    for (auto i : res)
    {
        std::cout << i.fi << " " << i.se << "\n";
    }
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> m;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> n;
    for (int j = 1; j <= n; j++)
    {
        std::cin >> b[j];
    }

    sieve();

    ::va.clear();
    ::vb.clear();
    ::v.clear();

    for (int i = 1; i <= m; i++)
    {
        int x = a[i];
        for (int p : primes)
        {
            if (1LL * p * p > x)
                break;
            if (x % p == 0)
            {
                int cnt = 0;
                while (x % p == 0)
                {
                    x /= p;
                    cnt++;
                }
                ::va[p] += cnt;
            }
        }
        if (x > 1)
        {
            ::va[x]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x = b[i];
        for (int p : primes)
        {
            if (1LL * p * p > x)
                break;
            if (x % p == 0)
            {
                int cnt = 0;
                while (x % p == 0)
                {
                    x /= p;
                    cnt++;
                }
                ::vb[p] += cnt;
            }
        }
        if (x > 1)
        {
            ::vb[x]++;
        }
    }

    for (auto &it : ::va)
        ::v.pb(it.first);
    for (auto &it : ::vb)
        ::v.pb(it.first);
    std::sort(::v.begin(), ::v.end());
    ::v.erase(std::unique(::v.begin(), ::v.end()), ::v.end());


    if (A <= 25 && B <= 25)
    {
        sub3();
    }
    else if (check_sub2)
    {
        sub2();
    }
    else
    {
        sub3();
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣾⣿⣿⣿⣿⣷⣦⣤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⡿⡿⡿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⡿⠯⣩⣾⣾⣿⣿⣿⡚⣛⣝⢕⢕⢝⢝⢽⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⡿⣨⣿⣿⣿⣿⠿⣛⡭⢓⣿⣿⣷⣕⢷⣥⠥⢝⣿⣿⣿⡿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⡿⢿⠟⣭⣿⣿⣿⣫⣾⡫⣯⢿⢷⢶⢿⣶⢮⣟⣩⣴⡻⢷⡆⣿⣿⢕⢙⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⡛⡡⠊⣴⣿⣿⣟⢽⢟⣿⣑⣙⣾⠺⣸⡾⡏⣚⡛⣿⣯⡡⢜⣧⢝⣿⣞⡪⡹⣿⣿⣿⡏⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡯⡫⢪⣒⠿⣽⣿⣟⣼⣿⣿⣕⣪⣿⠯⣫⣿⡯⡭⣮⣻⣿⣯⢝⣿⣿⣬⢼⣿⣪⡫⡻⣿⣿⣿⡍⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⣴⡿⡾⠺⡴⣾⣿⣿⢗⣟⣿⣿⠅⣶⣿⣯⢎⣾⡿⡪⣾⡧⣾⣿⠵⢕⣿⣿⣇⢵⣿⣏⡮⠪⣻⣿⡾⡮⡹⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣧⣿⣴⣿⣿⢓⣟⣿⢯⢏⣵⡿⣹⣿⣺⣿⡏⡇⣿⡿⣿⣿⢹⢘⣿⣿⣯⠕⣿⣿⣿⡬⣏⢻⣿⠯⣭⢺⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣟⣼⣿⣿⣿⣿⣿⢵⣿⣿⡯⡼⡲⣿⠗⣻⣿⣾⡟⢽⢺⣿⡧⣿⡿⡧⡣⣿⣿⡿⡟⣿⣿⣿⣷⢻⡼⣿⣿⣿⠲⣻⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣀⠀⣀⣠⡤⣾⣞⣿⣿⣿⣿⣿⣟⡭⣿⣾⣿⠀⠨⣸⡏⠀⢹⣿⣿⠘⡗⢼⣿⣿⢿⢸⡺⠺⣿⣿⣟⡢⣿⣿⣿⣿⣿⣿⢜⣿⣿⡯⣪⣧⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠙⠚⠋⣡⢟⣾⣿⣿⣿⣟⢿⠭⢵⣻⣿⣿⠀⢨⣺⡇⠀⠸⣿⣿⠀⠹⢝⣿⣿⣿⡇⢯⡪⡮⣿⡯⡪⢿⣿⣿⣿⣿⣿⣷⢛⣿⣿⣾⣾⠀⠀⠀⢀⡴⠏⠻⠛⡧⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡼⣻⣿⣿⣿⣿⡟⣗⣳⢼⣏⡻⡩⠿⢤⠼⢾⣿⠀⠀⠹⢿⣇⠀⠳⣽⣿⣿⣷⡈⢮⡪⣻⣟⣒⣻⣿⣿⣿⣿⣿⣿⣕⣿⣿⣿⣿⡆⠀⠀⠘⢷⡆⣠⣙⡇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢯⣽⣿⣟⣥⢹⣵⣿⢮⣿⣷⣴⣿⣶⣾⣦⣤⣄⠀⠀⠀⠈⠉⠁⠀⠈⠙⢻⣛⡻⡎⢻⣽⣯⣆⣯⣿⣿⣿⣿⣿⣿⣧⡺⢟⣱⠞⣦⣀⡀⠀⠈⠙⠉⠉⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠻⡎⣶⣿⣿⣫⣾⣿⠟⠋⠁⠀⠉⠉⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣥⣩⠛⠲⣼⣗⢧⢖⡺⣿⣯⣺⣻⣿⣿⡄⢯⡈⠀⠀⣴⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⢫⣿⣿⣿⣫⣿⣿⡗⠀⢀⠂⡄⠀⠀⠀⠀⠀⠐⠳⠒⠀⠀⠀⠀⠉⠉⠙⠿⢯⣒⣼⣯⢝⣿⣮⡻⣿⣧⣪⡻⣿⡏⡸⠧⠼⣦⠉⢳⠋⢹⡆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⣿⣿⣿⣿⣿⣿⡧⠢⠃⡐⠀⠀⠀⡖⠒⠤⠤⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⡀⡹⢿⣿⠗⣿⣿⣿⣾⣯⡿⡪⡿⣿⣞⡟⣵⠛⠁⠀⠀⠛⣶⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣽⣧⠆⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠈⠉⠙⢳⡄⠀⡰⡜⡠⢁⠽⢿⣽⣿⣿⣿⣿⣿⣮⢮⣻⣗⣿⣬⣛⣿⣀⡽⠛⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣷⣄⠀⠀⠀⠀⠹⡀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⠀⢠⢠⢁⠎⣠⣿⣿⣿⣿⣿⣿⢿⣿⣟⣽⣿⣿⣿⣿⠈⠉⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣰⣻⣿⣿⣿⢻⣿⣿⣿⣕⣿⣿⣿⣿⣷⣦⡀⠀⠀⠁⠀⠀⠀⠀⠀⣠⡤⠖⠁⠀⠀⠀⠁⠘⢎⣸⣺⣿⣿⣿⢿⣿⣽⣿⣿⣿⣿⣿⣿⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢰⣿⡿⣿⣿⢣⣿⢿⣿⢗⣽⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣤⣀⣀⣀⣀⣀⣀⣀⣀⣠⣤⣴⣶⣿⣿⣿⡾⣿⣿⣷⢽⣷⣿⣿⣿⣿⣿⣿⣿⣾⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣾⣰⣿⣯⢞⣷⣿⣟⣅⣿⣿⣿⠿⠿⠿⠿⠿⠛⠛⠛⠿⣿⣯⡿⡫⡡⠽⣿⠽⠟⣿⣿⣿⣿⣿⣿⣺⣿⣿⣗⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣻⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣿⣇⣿⣽⢳⣿⣿⠱⣼⡟⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣯⠾⠚⠉⠀⠀⠀⣟⢛⡿⠛⠉⣻⣿⣿⣿⣻⡧⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣧⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⢿⡿⣯⣽⣺⣿⣟⢴⢟⣥⣛⡇⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⠋⠉⠀⠀⠀⠀⠀⠀⣻⠞⠁⠀⠀⣯⣿⣿⣿⣟⣕⣿⡿⣿⣿⣿⣿⣿⣿⣫⡯⣯⣿⣷⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⡺⣺⡿⠿⣾⣿⢣⡭⢿⠀⠹⠖⢶⡀⠀⠀⠀⠀⠀⡼⢭⣉⡀⠀⠀⠀⠀⠀⢀⡜⠁⠀⠀⠀⠸⣿⣿⣿⣿⢷⣗⢿⣿⡿⢋⣹⣿⣿⣿⣿⡪⡿⣾⣺⣿⣄⠀⠀⠀
⠀⠀⠀⢀⡼⣯⣾⣯⣯⣽⣿⣿⠜⢦⡤⠀⠀⢲⡟⠀⠀⠀⠀⠀⢐⡇⠀⠀⠉⠛⠒⠶⠶⣶⠋⠀⠀⠀⠀⠀⣮⣾⣿⣿⣿⣟⣿⣝⢽⠞⣑⢑⣿⣿⣿⣿⡯⣯⣻⣯⣯⣽⣦⠀⠀
⠀⠀⢠⣻⣮⣿⣟⣜⢿⢽⣿⣟⠀⡸⣤⡼⠷⡶⠇⠀⠀⠀⠀⠀⢸⢤⡀⠀⠀⠀⠀⢀⡴⠁⠀⠀⠀⠀⠀⢰⣻⣿⣿⢿⣿⡯⣿⣷⢿⣇⠆⠄⣿⣿⣿⣿⣿⡿⣾⣿⣷⡿⢿⣆⠀
⠀⣰⣿⣷⣿⣿⣷⣝⣵⢽⡿⠫⠰⠸⢸⢸⠸⣿⢇⣀⣠⣄⠀⠀⢸⠀⠀⠀⠀⠉⢉⡟⠀⠀⠀⠀⠀⠀⠀⣇⣿⣿⡏⣾⣿⡿⣿⣿⣺⡻⣴⠙⢾⣿⣿⣿⣿⣷⣿⢿⣿⣿⣺⡻⡇
⢸⡧⢽⣿⣿⣿⣿⠝⣷⠻⠟⢻⡆⠊⡮⠊⣇⠟⣿⡈⠃⠼⣆⠀⠸⠀⠀⠀⠀⢀⠎⠀⠀⠀⠀⠀⠀⠀⢰⣕⢿⣿⢿⢯⣿⣿⣿⣿⣮⡯⡷⣎⣻⣿⣿⣿⣿⣿⣿⣽⣿⣿⣫⡯⣧
⠈⢿⢿⣿⣿⣿⣿⠇⡟⢀⠀⢈⣹⡆⣸⡯⢻⣌⠷⢶⣀⡶⠛⠀⠀⠀⠀⠀⢀⡎⠀⠀⠀⠀⠀⢀⣠⣲⡿⣗⣿⣿⣽⣗⣿⣿⣿⣿⣿⣿⡫⣿⣿⣿⣿⣿⣿⣿⣗⣿⣿⣿⡷⣪⣿
⠀⠀⠛⣿⣿⣿⣿⢵⣽⣟⠦⠞⠁⡊⡪⣿⢨⡿⣯⣳⣭⣤⡀⠀⢠⠀⠀⠀⡘⠀⠀⠀⢀⣤⣾⡿⢋⣥⢾⢷⣷⢿⣇⢿⣏⣿⣿⣿⣿⣯⡿⣯⣺⣿⣿⣿⣵⣿⣿⣿⣿⣿⡯⡫⡎
⠀⠀⠀⠈⢿⣿⣿⡟⣿⣧⣿⣬⠠⢀⠡⢣⣼⡧⠊⠻⣝⣿⣿⢆⢸⠀⠀⢰⠁⢀⣠⣾⡿⠟⣡⠔⠋⠔⡀⡼⣟⣾⣽⣄⣿⣝⣿⣿⣿⣷⣿⣿⢻⣎⣿⣽⣿⣿⡿⣿⣿⣿⡯⣻⠇
*/