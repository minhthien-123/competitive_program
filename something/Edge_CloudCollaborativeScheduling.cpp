#include <bits/stdc++.h>
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define INF 1e18

const int inf = 1e9;

enum ReqState
{
    ARRIVED,
    P_PRE_RUNNING,
    WAITING_UP_PRE,
    READY_FOR_P_PROC,
    P_PROC_RUNNING,
    WAITING_DOWN_PRE,
    DOWN_PRE_DONE,
    P_POST_RUNNING,
    READY_FOR_DEC,
    D_PRE_RUNNING,
    WAITING_UP_DEC,
    UP_DEC_DONE,
    D_PROC_RUNNING,
    WAITING_DOWN_DEC,
    DOWN_DEC_DONE,
    D_POST_RUNNING,
    FINISHED
};

struct Request
{
    int id;
    int Lin;
    int remote_assigned;
    int current_layer;
    ReqState state;
    double arrive_time;
    double last_token_time;
    int tokens_done;
};

struct TimeRow
{
    double batch_size, pp, ppr, ppo, dp, dpr, dpo;
    bool operator<(const TimeRow &o) const { return batch_size < o.batch_size; }
};

double interpolate(const std::vector<std::pair<double, double>> &pts, double x)
{
    if (pts.empty())
        return 1.0;
    if (x <= pts.front().first)
        return pts.front().second;
    if (x >= pts.back().first)
        return pts.back().second;
    for (int i = 0; i < (int)pts.size() - 1; ++i)
    {
        if (x >= pts[i].first && x <= pts[i + 1].first)
        {
            double t = (x - pts[i].first) / (pts[i + 1].first - pts[i].first);
            return pts[i].second + t * (pts[i + 1].second - pts[i].second);
        }
    }
    return pts.back().second;
}

int get_chunk_size(int lin, int layers, bool safe_to_full, bool tp_focused, double S, double target_slo, const std::vector<std::pair<double, double>> &valid_ppr)
{
    if (tp_focused || safe_to_full)
        return layers;

    double total_pp_time = interpolate(valid_ppr, lin);
    double time_per_layer = total_pp_time / layers;
    if (time_per_layer < 1e-9)
        return layers;

    double target_time = std::max(target_slo * 0.3, S * 1.5);
    int chunk = (int)(target_time / time_per_layer);
    return std::max(1, std::min(layers, chunk));
}

void solve()
{
    int K, bytes_per_token, num_layers;
    double S, latency_in_ms, bandwidth_gbps;

    if (!(std::cin >> K >> S >> latency_in_ms >> bandwidth_gbps >> bytes_per_token >> num_layers))
        return;

    double SLO1, SLO2, tp_UB, tp_base, dist_base, w_tp, w_c;
    std::cin >> SLO1 >> SLO2 >> tp_UB >> tp_base >> dist_base >> w_tp >> w_c;

    double s1 = std::max(0.001, SLO1);
    double s2 = std::max(0.001, SLO2);

    int N;
    std::cin >> N;
    std::vector<TimeRow> t_table(N);
    std::vector<std::pair<double, double>> valid_dpr, valid_ppr;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> t_table[i].batch_size >> t_table[i].pp >> t_table[i].ppr >> t_table[i].ppo >> t_table[i].dp >> t_table[i].dpr >> t_table[i].dpo;
    }
    std::sort(t_table.begin(), t_table.end());
    for (auto &r : t_table)
    {
        if (r.dpr != -1)
            valid_dpr.push_back({r.batch_size, r.dpr});
        if (r.ppr != -1)
            valid_ppr.push_back({r.batch_size, r.ppr});
    }

    bool tp_focused = (w_tp > w_c * 2.0);

    int optimal_d_batch = 1;
    int low = 1, high = 4096, ans = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        double est_time = interpolate(valid_dpr, mid) + S;
        if (est_time <= std::max(SLO2 * 0.5, S * 2.0))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    optimal_d_batch = std::max(1, ans);
    if (tp_focused)
        optimal_d_batch = 4096;

    bool E_free = true;
    std::vector<bool> C_free(K, true);
    std::vector<Request> requests;
    std::vector<int> active_requests(K, 0);
    std::vector<int> active_decoding(K, 0);
    std::vector<long long> server_load_lin(K, 0);

    while (true)
    {
        std::string t_str;
        if (!(std::cin >> t_str))
            break;
        if (t_str == "END")
            break;

        double current_time = std::stod(t_str);
        int e;
        std::cin >> e;

        std::vector<int> pending_fins;

        for (int i = 0; i < e; ++i)
        {
            std::string event_type;
            std::cin >> event_type;

            if (event_type == "ARR")
            {
                int rid, lin;
                std::cin >> rid >> lin;
                if (rid >= (int)requests.size())
                    requests.resize(rid + 1);
                requests[rid] = {rid, lin, -1, 0, ARRIVED, current_time, 0.0, 0};
            }
            else if (event_type == "TDN")
            {
                std::string server, task_name, task2;
                std::cin >> server >> task_name >> task2;

                if (task_name == "P")
                {
                    if (task2 == "PRE")
                    {
                        int rem, rid;
                        double dur;
                        std::cin >> rem >> rid >> dur;
                        E_free = true;
                        requests[rid].state = WAITING_UP_PRE;
                    }
                    else if (task2 == "PROC")
                    {
                        int ls, le, rem, rid;
                        double dur;
                        std::cin >> ls >> le >> rem >> rid >> dur;
                        C_free[rem] = true;
                        requests[rid].current_layer = le;
                        if (le == num_layers)
                            requests[rid].state = WAITING_DOWN_PRE;
                        else
                            requests[rid].state = READY_FOR_P_PROC;
                    }
                    else if (task2 == "POST")
                    {
                        int rem, rid;
                        double dur;
                        std::cin >> rem >> rid >> dur;
                        E_free = true;
                        requests[rid].state = READY_FOR_DEC;
                        requests[rid].last_token_time = current_time;
                    }
                }
                else if (task_name == "D")
                {
                    if (task2 == "PRE")
                    {
                        int rem, m;
                        std::cin >> rem >> m;
                        std::vector<int> rids(m);
                        for (int j = 0; j < m; ++j)
                            std::cin >> rids[j];
                        double dur;
                        std::cin >> dur;
                        E_free = true;
                        for (int id : rids)
                            requests[id].state = WAITING_UP_DEC;
                    }
                    else if (task2 == "PROC")
                    {
                        int rem, m;
                        std::cin >> rem >> m;
                        std::vector<int> rids(m);
                        for (int j = 0; j < m; ++j)
                            std::cin >> rids[j];
                        double dur;
                        std::cin >> dur;
                        C_free[rem] = true;
                        for (int id : rids)
                            requests[id].state = WAITING_DOWN_DEC;
                    }
                    else if (task2 == "POST")
                    {
                        int dummy_rem, m;
                        std::cin >> dummy_rem >> m;
                        std::vector<int> rids(m);
                        for (int j = 0; j < m; ++j)
                            std::cin >> rids[j];
                        double dur;
                        std::cin >> dur;
                        E_free = true;
                        for (int id : rids)
                        {
                            requests[id].tokens_done++;
                            requests[id].last_token_time = current_time;
                            if (requests[id].tokens_done == 1)
                            {
                                int true_rem = requests[id].remote_assigned;
                                active_decoding[true_rem]++;
                            }
                            if (requests[id].state != FINISHED)
                                requests[id].state = READY_FOR_DEC;
                        }
                    }
                }
            }
            else if (event_type == "XDN")
            {
                std::string dir, pre_dec;
                int rem, m;
                long long size;
                std::cin >> dir >> rem >> size >> pre_dec >> m;
                std::vector<int> rids(m);
                for (int j = 0; j < m; ++j)
                    std::cin >> rids[j];

                if (dir == "UP" && pre_dec == "PRE")
                    requests[rids[0]].state = READY_FOR_P_PROC;
                else if (dir == "DOWN" && pre_dec == "PRE")
                    requests[rids[0]].state = DOWN_PRE_DONE;
                else if (dir == "UP" && pre_dec == "DEC")
                {
                    for (int id : rids)
                        requests[id].state = UP_DEC_DONE;
                }
                else if (dir == "DOWN" && pre_dec == "DEC")
                {
                    for (int id : rids)
                        requests[id].state = DOWN_DEC_DONE;
                }
            }
            else if (event_type == "FIN")
            {
                int rid;
                std::cin >> rid;
                pending_fins.push_back(rid);
            }
        }

        for (int rid : pending_fins)
        {
            requests[rid].state = FINISHED;
            int rem = requests[rid].remote_assigned;
            if (rem != -1)
            {
                server_load_lin[rem] -= requests[rid].Lin;
                active_requests[rem]--;
                if (requests[rid].tokens_done >= 1)
                {
                    active_decoding[rem]--;
                }
            }
        }

        std::vector<int> down_dec_done, down_pre_done, ready_for_dec, arrived;
        std::vector<std::vector<int>> up_dec_done(K), ready_for_p_proc(K);

        for (auto &req : requests)
        {
            if (req.state == DOWN_DEC_DONE)
                down_dec_done.push_back(req.id);
            else if (req.state == DOWN_PRE_DONE)
                down_pre_done.push_back(req.id);
            else if (req.state == READY_FOR_DEC)
                ready_for_dec.push_back(req.id);
            else if (req.state == ARRIVED)
                arrived.push_back(req.id);
            else if (req.remote_assigned >= 0)
            {
                if (req.state == UP_DEC_DONE)
                    up_dec_done[req.remote_assigned].push_back(req.id);
                else if (req.state == READY_FOR_P_PROC)
                    ready_for_p_proc[req.remote_assigned].push_back(req.id);
            }
        }

        std::vector<std::string> assigns;

        if (E_free)
        {
            bool e_assigned = false;

            if (!down_dec_done.empty())
            {
                std::string s = "E D POST -1 " + std::to_string(down_dec_done.size());
                for (int id : down_dec_done)
                {
                    s += " " + std::to_string(id);
                    requests[id].state = D_POST_RUNNING;
                }
                assigns.push_back(s);
                e_assigned = true;
            }
            else if (!down_pre_done.empty())
            {
                double min_arr = INF;
                int best_id = down_pre_done[0];
                for (int cand : down_pre_done)
                {
                    if (requests[cand].arrive_time < min_arr)
                    {
                        min_arr = requests[cand].arrive_time;
                        best_id = cand;
                    }
                }
                assigns.push_back("E P POST " + std::to_string(requests[best_id].remote_assigned) + " " + std::to_string(best_id));
                requests[best_id].state = P_POST_RUNNING;
                e_assigned = true;
            }
            else
            {
                bool can_d = !ready_for_dec.empty();
                bool can_p = !arrived.empty();

                double max_d_urg = -1;
                if (can_d)
                {
                    for (int id : ready_for_dec)
                    {
                        double u = (requests[id].tokens_done == 0) ? ((current_time - requests[id].last_token_time) / (s2 * 10.0)) : ((current_time - requests[id].last_token_time) / s2);
                        max_d_urg = std::max(max_d_urg, u);
                    }
                }

                double max_p_urg = -1;
                if (can_p)
                {
                    for (int id : arrived)
                        max_p_urg = std::max(max_p_urg, (current_time - requests[id].arrive_time) / s1);
                }

                bool do_p = false, do_d = false;

                if (can_d && can_p)
                {
                    bool has_idle_server = false;
                    for (int k = 0; k < K; ++k)
                        if (active_requests[k] == 0)
                            has_idle_server = true;

                    if (has_idle_server)
                    {
                        do_p = true;
                    }
                    else
                    {
                        if (max_d_urg >= max_p_urg * 0.8)
                            do_d = true;
                        else
                            do_p = true;
                    }
                }
                else if (can_d)
                    do_d = true;
                else if (can_p)
                    do_p = true;

                if (do_d)
                {
                    std::vector<int> sorted_dec = ready_for_dec;
                    std::sort(sorted_dec.begin(), sorted_dec.end(), [&](int a, int b)
                              {
                                  double urg_a = (requests[a].tokens_done == 0) ? -1 : (current_time - requests[a].last_token_time);
                                  double urg_b = (requests[b].tokens_done == 0) ? -1 : (current_time - requests[b].last_token_time);
                                  return urg_a > urg_b; });

                    std::vector<int> count_per_k(K, 0);
                    std::vector<int> d_pre_group;
                    for (int id : sorted_dec)
                    {
                        int rem = requests[id].remote_assigned;
                        if (count_per_k[rem] < optimal_d_batch)
                        {
                            d_pre_group.push_back(id);
                            count_per_k[rem]++;
                        }
                    }
                    std::string s = "E D PRE -1 " + std::to_string(d_pre_group.size());
                    for (int id : d_pre_group)
                    {
                        s += " " + std::to_string(id);
                        requests[id].state = D_PRE_RUNNING;
                    }
                    assigns.push_back(s);
                    e_assigned = true;
                }
                else if (do_p)
                {
                    int best_p = arrived[0];
                    int min_lin = inf;
                    for (int cand : arrived)
                    {
                        if (requests[cand].Lin < min_lin)
                        {
                            min_lin = requests[cand].Lin;
                            best_p = cand;
                        }
                    }

                    int best_k = 0;
                    long long min_score = INF;
                    for (int k = 0; k < K; ++k)
                    {
                        long long score = active_requests[k] * 1000000LL + server_load_lin[k];
                        if (score < min_score)
                        {
                            min_score = score;
                            best_k = k;
                        }
                    }

                    active_requests[best_k]++;
                    server_load_lin[best_k] += requests[best_p].Lin;
                    requests[best_p].remote_assigned = best_k;
                    requests[best_p].state = P_PRE_RUNNING;
                    assigns.push_back("E P PRE " + std::to_string(best_k) + " " + std::to_string(best_p));
                    e_assigned = true;
                }
            }
            if (e_assigned)
                E_free = false;
        }
        for (int k = 0; k < K; ++k)
        {
            if (!C_free[k])
                continue;

            bool c_assigned = false;
            bool can_d = !up_dec_done[k].empty();
            bool can_p = !ready_for_p_proc[k].empty();

            double max_d_urg = -1;
            if (can_d)
            {
                for (int id : up_dec_done[k])
                {
                    double u = (requests[id].tokens_done == 0) ? ((current_time - requests[id].last_token_time) / (s2 * 10.0)) : ((current_time - requests[id].last_token_time) / s2);
                    max_d_urg = std::max(max_d_urg, u);
                }
            }

            double max_p_urg = -1;
            if (can_p)
            {
                for (int id : ready_for_p_proc[k])
                    max_p_urg = std::max(max_p_urg, (current_time - requests[id].arrive_time) / s1);
            }

            bool do_d = false, do_p = false;

            if (can_d && can_p)
            {
                if (max_d_urg >= max_p_urg * 0.8)
                    do_d = true;
                else
                    do_p = true;
            }
            else if (can_d)
                do_d = true;
            else if (can_p)
                do_p = true;

            if (do_d)
            {
                std::vector<int> sorted_dec = up_dec_done[k];
                std::sort(sorted_dec.begin(), sorted_dec.end(), [&](int a, int b)
                          {
                    double urg_a = (requests[a].tokens_done == 0) ? -1 : (current_time - requests[a].last_token_time);
                    double urg_b = (requests[b].tokens_done == 0) ? -1 : (current_time - requests[b].last_token_time);
                    return urg_a > urg_b; });

                int take = std::min((int)sorted_dec.size(), optimal_d_batch);
                std::string s = "C" + std::to_string(k) + " D PROC " + std::to_string(k) + " " + std::to_string(take);
                for (int i = 0; i < take; ++i)
                {
                    int id = sorted_dec[i];
                    s += " " + std::to_string(id);
                    requests[id].state = D_PROC_RUNNING;
                }
                assigns.push_back(s);
                c_assigned = true;
            }
            else if (do_p)
            {
                int best_p = ready_for_p_proc[k][0];
                int min_lin = inf;
                for (int cand : ready_for_p_proc[k])
                {
                    if (requests[cand].Lin < min_lin)
                    {
                        min_lin = requests[cand].Lin;
                        best_p = cand;
                    }
                }

                bool safe_to_full = (active_decoding[k] == 0);
                int step = get_chunk_size(requests[best_p].Lin, num_layers, safe_to_full, tp_focused, S, SLO2, valid_ppr);
                int ls = requests[best_p].current_layer;
                int le = std::min(num_layers, ls + step);

                assigns.push_back("C" + std::to_string(k) + " P PROC " + std::to_string(ls) + " " + std::to_string(le) + " " + std::to_string(k) + " " + std::to_string(best_p));
                requests[best_p].state = P_PROC_RUNNING;
                c_assigned = true;
            }
            if (c_assigned)
                C_free[k] = false;
        }

        std::cout << assigns.size() << "\n";
        for (const std::string &s : assigns)
            std::cout << s << "\n";
        std::cout << std::flush;
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    std::cerr << "\nTime elapsed: " << TIME << " s.\n";
    return 0;
}