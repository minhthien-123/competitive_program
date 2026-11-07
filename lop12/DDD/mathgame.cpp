#include <bits/stdc++.h>
#define task "mathgame"
#define __Thien_dep_trai__ signed main()
#define ll long long
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
#define bit_set(x, pos) ((x) |= (1ULL << (pos)))
#define bit_clear(x, pos) ((x) &= ~(1ULL << (pos)))
#define all(x) x.begin(), x.end()

const int maxn = 1e5;
const int maxv = 2600000;
const ll INF = 1e9;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;
const int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

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
    return (x % mod * (y % mod)) % mod;
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

int n, k;
int a[maxn + 7][12];

int edge_val[maxv + 7];
int edge_card[maxv + 7];
int tmp_val[maxv + 7];
int tmp_card[maxv + 7];
int head[maxv + 7];
int vals[maxv + 7];
int num_vals = 0;

int match_card[maxn + 7];
int match_val[maxv + 7];
int has_target[maxv + 7];
int rev_val[maxv + 7];
int card_head[maxn + 7];
int card_cur[maxn + 7];
int vis[maxn + 7];
int dead[maxn + 7];
int vis_cards[maxn + 7];
int trace_val[maxn + 7];
int in_seg[maxn + 7];
int q[maxn + 7];
int vis_time = 0;
int dead_id = 0;
int seg_time = 0;

void solve()
{
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            std::cin >> a[i][j];
        }
    }

    int total_edges = 0;
    int buf[4096];

    for (int i = 1; i <= n; i++)
    {
        int sz_v = 1;
        buf[0] = a[i][1];
        for (int j = 2; j <= k; j++)
        {
            int x = a[i][j];
            for (int t = 0; t < sz_v; t++)
            {
                buf[t + sz_v] = buf[t] - x;
                buf[t] += x;
            }
            sz_v <<= 1;
        }
        std::sort(buf, buf + sz_v);
        sz_v = std::unique(buf, buf + sz_v) - buf;

        for (int t = 0; t < sz_v; t++)
        {
            edge_val[total_edges] = buf[t];
            edge_card[total_edges] = i;
            total_edges++;
        }
    }

    int cnt[256];
    int *src_v = edge_val, *src_c = edge_card;
    int *dst_v = tmp_val, *dst_c = tmp_card;

    for (int shift = 0; shift < 32; shift += 8)
    {
        std::memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < total_edges; i++)
        {
            uint32_t u = (uint32_t)src_v[i] ^ 0x80000000u;
            cnt[(u >> shift) & 0xFF]++;
        }
        int sum = 0;
        for (int b = 0; b < 256; b++)
        {
            int c = cnt[b];
            cnt[b] = sum;
            sum += c;
        }
        for (int i = 0; i < total_edges; i++)
        {
            uint32_t u = (uint32_t)src_v[i] ^ 0x80000000u;
            int pos = cnt[(u >> shift) & 0xFF]++;
            dst_v[pos] = src_v[i];
            dst_c[pos] = src_c[i];
        }
        std::swap(src_v, dst_v);
        std::swap(src_c, dst_c);
    }

    num_vals = 0;
    for (int i = 0; i < total_edges;)
    {
        int j = i + 1;
        while (j < total_edges && edge_val[j] == edge_val[i])
        {
            j++;
        }
        num_vals++;
        vals[num_vals] = edge_val[i];
        head[num_vals] = i;
        i = j;
    }
    head[num_vals + 1] = total_edges;

    for (int i = 1; i <= n + 1; i++)
    {
        card_head[i] = 0;
    }
    for (int i = 0; i < total_edges; i++)
    {
        card_head[edge_card[i] + 1]++;
    }
    for (int i = 1; i <= n + 1; i++)
    {
        card_head[i] += card_head[i - 1];
        card_cur[i] = card_head[i];
    }
    for (int v = 1; v <= num_vals; v++)
    {
        for (int e = head[v]; e < head[v + 1]; e++)
        {
            int c = edge_card[e];
            rev_val[card_cur[c]++] = v;
        }
    }

    vii segs;
    for (int i = 1; i <= num_vals;)
    {
        int j = i;
        while (j + 1 <= num_vals && vals[j + 1] == vals[j] + 1)
        {
            j++;
        }
        segs.pb({i, j});
        i = j + 1;
    }

    std::sort(all(segs), [](const ii &A, const ii &B) {
        return (A.se - A.fi) > (B.se - B.fi);
    });

    int ans = 0;

    for (const auto &seg : segs)
    {
        int L = seg.fi;
        int maxR = seg.se;

        if (maxR - L + 1 <= ans || ans == n)
        {
            break;
        }

        seg_time++;
        int c_cnt[2] = {0, 0};
        for (int v = L; v <= maxR; v++)
        {
            int p = v & 1;
            for (int e = head[v]; e < head[v + 1]; e++)
            {
                int c = edge_card[e];
                if (in_seg[c] != seg_time)
                {
                    in_seg[c] = seg_time;
                    c_cnt[p]++;
                }
            }
        }

        int limit = std::min({maxR - L + 1, c_cnt[0] + c_cnt[1], 2 * c_cnt[0] + 1, 2 * c_cnt[1] + 1});
        if (limit <= ans)
        {
            continue;
        }

        int curL = L;
        dead_id++;
        int cur_dead_id[2] = {++dead_id, ++dead_id};
        for (int R = L; R <= maxR; R++)
        {
            if (maxR - curL + 1 <= ans || ans >= limit)
            {
                break;
            }

            int p = R & 1;
            int d_id = cur_dead_id[p];

            int matched_direct = 0;
            for (int e = head[R]; e < head[R + 1]; e++)
            {
                int card = edge_card[e];
                if (match_card[card] == 0)
                {
                    matched_direct = card;
                    break;
                }
            }

            if (matched_direct != 0)
            {
                match_card[matched_direct] = R;
                match_val[R] = matched_direct;
                ans = std::max(ans, R - curL + 1);
                continue;
            }

            // Phase A: BFS to find a free card (pre == 0), skipping dead cards of parity p
            vis_time++;
            int qh = 0, qt = 0;
            q[qt++] = R;
            int found_card = 0;
            int num_vis = 0;

            while (qh < qt && found_card == 0)
            {
                int v = q[qh++];
                for (int e = head[v]; e < head[v + 1]; e++)
                {
                    int card = edge_card[e];
                    int pre = match_card[card];
                    if (pre == 0)
                    {
                        trace_val[card] = v;
                        found_card = card;
                        break;
                    }
                    if (dead[card] != d_id && vis[card] != vis_time)
                    {
                        vis[card] = vis_time;
                        vis_cards[num_vis++] = card;
                        trace_val[card] = v;
                        q[qt++] = pre;
                    }
                }
            }

            if (found_card != 0)
            {
                int cur_c = found_card;
                while (cur_c != 0)
                {
                    int v = trace_val[cur_c];
                    int next_c = match_val[v];
                    match_card[cur_c] = v;
                    match_val[v] = cur_c;
                    cur_c = next_c;
                }
                ans = std::max(ans, R - curL + 1);
                continue;
            }

            for (int i = 0; i < num_vis; i++)
            {
                dead[vis_cards[i]] = d_id;
            }

            // Phase B: No free card reachable; smallest possible reachable value in [curL, R] has same parity as R
            int target_L = curL + ((R ^ curL) & 1);
            if (maxR - target_L <= ans)
            {
                break;
            }

            vis_time++;
            int target_card = (target_L < R) ? match_val[target_L] : 0;
            if (target_card != 0)
            {
                for (int e = card_head[target_card]; e < card_head[target_card + 1]; e++)
                {
                    has_target[rev_val[e]] = vis_time;
                }
            }

            qh = 0;
            qt = 0;
            q[qt++] = R;
            int min_pre = inf;
            bool hit_target = false;
            num_vis = 0;

            if (target_card != 0 && has_target[R] == vis_time)
            {
                vis[target_card] = vis_time;
                trace_val[target_card] = R;
                min_pre = target_L;
                hit_target = true;
            }

            while (qh < qt && !hit_target)
            {
                int v = q[qh++];
                for (int e = head[v]; e < head[v + 1]; e++)
                {
                    int card = edge_card[e];
                    if (vis[card] != vis_time)
                    {
                        vis[card] = vis_time;
                        vis_cards[num_vis++] = card;
                        trace_val[card] = v;
                        int pre = match_card[card];
                        if (pre < min_pre)
                        {
                            min_pre = pre;
                            if (pre == target_L)
                            {
                                hit_target = true;
                                break;
                            }
                        }
                        if (has_target[pre] == vis_time)
                        {
                            vis[target_card] = vis_time;
                            trace_val[target_card] = pre;
                            min_pre = target_L;
                            hit_target = true;
                            break;
                        }
                        q[qt++] = pre;
                    }
                }
            }

            if (min_pre == inf)
            {
                while (curL < R)
                {
                    int c = match_val[curL];
                    if (c != 0)
                    {
                        int cp = curL & 1;
                        if (dead[c] == cur_dead_id[cp])
                        {
                            cur_dead_id[cp] = ++dead_id;
                        }
                        match_card[c] = 0;
                        match_val[curL] = 0;
                    }
                    curL++;
                }
                curL = R + 1;
            }
            else
            {
                if (maxR - min_pre <= ans)
                {
                    break;
                }
                int cur_c = match_val[min_pre];
                while (curL < min_pre)
                {
                    int c = match_val[curL];
                    if (c != 0)
                    {
                        int cp = curL & 1;
                        if (dead[c] == cur_dead_id[cp])
                        {
                            cur_dead_id[cp] = ++dead_id;
                        }
                        match_card[c] = 0;
                        match_val[curL] = 0;
                    }
                    curL++;
                }
                if (!hit_target)
                {
                    for (int i = 0; i < num_vis; i++)
                    {
                        dead[vis_cards[i]] = cur_dead_id[p];
                    }
                }
                match_card[cur_c] = 0;
                match_val[min_pre] = 0;
                curL = min_pre + 1;

                while (cur_c != 0)
                {
                    int v = trace_val[cur_c];
                    int next_c = match_val[v];
                    match_card[cur_c] = v;
                    match_val[v] = cur_c;
                    cur_c = next_c;
                }
            }
        }

        for (int idx = curL; idx <= maxR; idx++)
        {
            if (match_val[idx] != 0)
            {
                match_card[match_val[idx]] = 0;
                match_val[idx] = 0;
            }
        }
    }

    std::cout << ans;
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

    int tt = 1;
    // std::cin >> tt;
    while (tt--)
    {
        solve();
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