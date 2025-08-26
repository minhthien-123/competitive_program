#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 998244353;
void add(int &a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}

const int LG = 30; // Số bit từ 30 xuống 0

struct Node {
    int child[2];
    int sum;
    Node() {
        child[0] = child[1] = -1;
        sum = 0;
    }
};

struct Trie {
    vector<Node> nodes;

    Trie() {
        nodes.emplace_back(); // Khởi tạo node gốc
    }

    void add_value(int x, int val) {
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (nodes[pos].child[c] == -1) {
                nodes[pos].child[c] = nodes.size();
                nodes.emplace_back();
            }
            pos = nodes[pos].child[c];
            add(nodes[pos].sum, val);
        }
    }

    int query(int x) {
        int pos = 0, res = 0;
        for (int i = LG; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (bit == 0) {
                if (nodes[pos].child[0] == -1) return res;
                pos = nodes[pos].child[0];
            } else {
                if (nodes[pos].child[0] != -1)
                    add(res, nodes[nodes[pos].child[0]].sum);
                if (nodes[pos].child[1] == -1) return res;
                pos = nodes[pos].child[1];
            }
        }
        add(res, nodes[pos].sum);
        return res;
    }
};

const int N = 3e5 + 5;
int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    Trie trie;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = trie.query(a[i]);
        add(res, cnt);
        trie.add_value(a[i], 1);
    }
    cout << res << endl;
    return 0;
}