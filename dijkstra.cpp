#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const ll INF = 1ll << 60;

struct Edge {
    ll to;
    ll w;
    Edge(ll to, ll w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }else return false;
}

int main() {
    int N, M, s;
    cin >> N >> M >> s;

    Graph G(N + 1);
    for (ll i = 0ll; i < M; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
        // inputによる
        G[b].push_back(Edge(a, w));
    }
    vector<bool> used(N + 1, false);
    vector<ll> dist(N+1, INF);
    dist[s] = 0;
    for (ll iter = 0ll; iter < N; iter++) {
        ll min_dist = INF;
        ll min_v = -1ll;
        for (ll v = 0; v < N; v++) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }

        }

        if (min_v == -1ll) break ;

        for (ll i = 0ll; i < G[min_v].size(); i++) {
            chmin(dist[G[min_v][i].to], dist[min_v] + G[min_v][i].w);
        }
        used[min_v] = true;
    }

    for (ll i = 1ll; i <= N; i++) {
        if (dist[i] < INF) cout << dist[i] << endl;
        else cout << -1 << endl;
    }
}