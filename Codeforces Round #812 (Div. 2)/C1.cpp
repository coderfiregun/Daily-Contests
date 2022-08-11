/*
Someone coded this using bipartite matching
Hopcroft or some other algorithm

We know that for every number from 0 to n — 1, we need a number to be added to it so that it's sum is a square number.

We also know that for each i, i + k == square_number, then k should be between 0 and n — 1 inclusive.

So we will iterate over all square numbers such that square_number — i <= n — 1, say k.

Then we will add an edge between i and k.

Since we need N pairs, and these pairs should not contain pairings with the same number, we can use bipartite matching.

To Try Out
https://iq.opengenus.org/hopcroft-karp-algorithm/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void fast (void) __attribute__ ((constructor));
void fast (void) { 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
} 

struct Random : std::mt19937 {
    using std::mt19937::mt19937;
    using std::mt19937::operator();
    static int64_t gen_seed() {
        return std::chrono::steady_clock::now().time_since_epoch().count();
    }
    Random() : std::mt19937(gen_seed()) {}
    template <class Int>
    auto operator()(Int a, Int b)
        -> std::enable_if_t<std::is_integral_v<Int>, Int> {
        return std::uniform_int_distribution<Int>(a, b)(*this);
    }
    template <class Int>
    auto operator()(Int a) -> std::enable_if_t<std::is_integral_v<Int>, Int> {
        return std::uniform_int_distribution<Int>(0, a - 1)(*this);
    }
    template <class Real>
    auto operator()(Real a, Real b)
        -> std::enable_if_t<std::is_floating_point_v<Real>, Real> {
        return std::uniform_real_distribution<Real>(a, b)(*this);
    }
};
 
template <bool ToShuffle = false>
struct bipartite_matching {
    int n_left, n_right, flow = 0;
    std::vector<std::vector<int>> g;
    std::vector<int> match_from_left, match_from_right;
 
    bipartite_matching(int _n_left, int _n_right)
        : n_left(_n_left),
          n_right(_n_right),
          g(_n_left),
          match_from_left(_n_left, -1),
          match_from_right(_n_right, -1),
          dist(_n_left) {}
 
    void add(int u, int v) { g[u].push_back(v); }
 
    std::vector<int> dist;
 
    void bfs() {
        std::queue<int> q;
        for (int u = 0; u < n_left; ++u) {
            if (!~match_from_left[u])
                q.push(u), dist[u] = 0;
            else
                dist[u] = -1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u])
                if (~match_from_right[v] && !~dist[match_from_right[v]]) {
                    dist[match_from_right[v]] = dist[u] + 1;
                    q.push(match_from_right[v]);
                }
        }
    }
 
    bool dfs(int u) {
        for (auto v : g[u])
            if (!~match_from_right[v]) {
                match_from_left[u] = v, match_from_right[v] = u;
                return true;
            }
        for (auto v : g[u])
            if (dist[match_from_right[v]] == dist[u] + 1 &&
                dfs(match_from_right[v])) {
                match_from_left[u] = v, match_from_right[v] = u;
                return true;
            }
        return false;
    }
 
    int get_max_matching() {
        if constexpr (ToShuffle) {
            Random rng;
            for (int i = 0; i < n_left; ++i)
                std::random_shuffle(std::begin(g[i]), std::end(g[i]), rng);
        }
        while (true) {
            bfs();
            int augment = 0;
            for (int u = 0; u < n_left; ++u)
                if (!~match_from_left[u]) augment += dfs(u);
            if (!augment) break;
            flow += augment;
        }
        return flow;
    }
 
    std::pair<std::vector<int>, std::vector<int>> minimum_vertex_cover() {
        std::vector<int> L, R;
        for (int u = 0; u < n_left; ++u) {
            if (!~dist[u])
                L.push_back(u);
            else if (~match_from_left[u])
                R.push_back(match_from_left[u]);
        }
        return {L, R};
    }
 
    std::vector<std::pair<int, int>> get_edges() {
        std::vector<std::pair<int, int>> ans;
        for (int u = 0; u < n_left; ++u)
            if (match_from_left[u] != -1)
                ans.emplace_back(u, match_from_left[u]);
        return ans;
    }
};
 
void solve() {
    int n; cin >> n;
    vector<int> sqrts;
    for(int i = 0; i <= n; i++) {
        sqrts.push_back(i * i);
    }
 
    int L = n, R = n;
    bipartite_matching<false> matching(L, R);
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < sqrts.size(); j++) {
            int next = sqrts[j] - i;
            if(next < 0) continue;
            if(next >= n) break;
            matching.add(i, next);
        }
    }
 
    matching.get_max_matching();
    vector<int> ans(n, 0);
    for (auto [u, v] : matching.get_edges()) {
        ans[u] = v;
    }
 
    for(int x : ans) cout << x << " ";
    cout << "\n";
}
 
signed main(void) {
    int tm = 1;
    cin >> tm;
    while(tm--) solve();
    
    return 0;
}