#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

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

    vector<ll> dist(N + 1, INF);
    dist[s] = 0;
    priority_queue<pair<ll, ll>,
                   vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>> que;
    que.push(make_pair(dist[s], s));
    while(!que.empty()) {
        ll v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    for (ll v = 1; v <= N; v++) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << -1 << endl;
    }
    return 0;
}
