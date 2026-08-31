#include "testlib.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, w, id;
};

int main(int argc, char *argv[])
{
    // Khởi tạo thư viện testlib
    registerTestlibCmd(argc, argv);

    // Đọc N, M, K từ file input
    int n = inf.readInt();
    int m = inf.readInt();
    int k = inf.readInt();

    vector<Edge> edges(m);
    vector<vector<int>> adj(n + 1);
    int high_priority_count = 0;

    for (int i = 0; i < m; i++)
    {
        edges[i].u = inf.readInt();
        edges[i].v = inf.readInt();
        edges[i].w = inf.readInt();
        edges[i].id = i;

        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);

        if (edges[i].w == 1)
        {
            high_priority_count++;
        }
    }

    // Đọc kết quả từ đáp án của Ban giám khảo (ans) và Thí sinh (ouf)
    string jans = ans.readWord();
    string pans = ouf.readWord();

    // Chuẩn hóa chuỗi về in hoa để so sánh cho an toàn
    for (char &c : jans)
        c = toupper(c);
    for (char &c : pans)
        c = toupper(c);

    if (jans == "NO")
    {
        if (pans == "YES")
        {
            quitf(_wa, "Sai! Truy vấn vô nghiệm nhưng thí sinh in YES.");
        }
        else if (pans != "NO")
        {
            quitf(_pe, "Sai định dạng! Mong đợi YES hoặc NO, nhưng đọc được: %s", pans.c_str());
        }
        quitf(_ok, "Đúng! Không tồn tại cách phân quyền.");
    }

    if (jans == "YES")
    {
        if (pans == "NO")
        {
            quitf(_wa, "Sai! Có tồn tại nghiệm nhưng thí sinh in NO.");
        }
        else if (pans != "YES")
        {
            quitf(_pe, "Sai định dạng! Mong đợi YES hoặc NO, nhưng đọc được: %s", pans.c_str());
        }

        // Đọc mảng phân quyền của thí sinh
        vector<int> color(m, 0);
        for (int i = 0; i < m; i++)
        {
            if (edges[i].w == 1)
            {
                // Đọc chỉ số đơn vị an ninh được gán (từ 1 đến K)
                color[i] = ouf.readInt(1, k, "unit_id");
            }
        }

        // Kiểm tra tính hợp lệ: với mỗi đơn vị c từ 1 đến K
        // Nếu bỏ qua các cạnh gán cho c, đỉnh 1 có đi tới được N không?
        vector<int> vis(n + 1, 0);

        for (int c = 1; c <= k; c++)
        {
            queue<int> q;
            q.push(1);
            vis[1] = c; // Dùng luôn c làm mốc visited để khỏi phải memset lại mảng

            bool reached = false;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                if (u == n)
                {
                    reached = true;
                    break;
                }

                for (int edge_idx : adj[u])
                {
                    // Bỏ qua các đường truyền được giao cho đơn vị c
                    if (color[edge_idx] == c)
                        continue;

                    int v = (edges[edge_idx].u == u) ? edges[edge_idx].v : edges[edge_idx].u;

                    if (vis[v] != c)
                    {
                        vis[v] = c;
                        q.push(v);
                    }
                }
            }

            if (reached)
            {
                quitf(_wa, "Sai logic! Vẫn tồn tại đường đi từ 1 đến N mà KHÔNG chứa đường truyền nào của đơn vị %d.", c);
            }
        }

        quitf(_ok, "Chính xác! Phân quyền hợp lệ cho toàn bộ %d đường truyền ưu tiên cao.", high_priority_count);
    }

    quitf(_fail, "Lỗi không xác định trong quá trình chấm.");
}