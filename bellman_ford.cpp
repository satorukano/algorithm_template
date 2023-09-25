#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const ll INF = 1ll << 60;

struct Edge {
    ll to;
    ll w;
    Edge(ll to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        retrun true;
    }else return false;
}

int main() {
    ll N, M, s;
    cin >> N >> M >> s;

    Graph G(N + 1);
    for (ll i = 0; i < M; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    bool exist_negative_cycle = false;
    vector<ll> dist(N + 1, INF);
    dist[s] = 0;
    for (ll iter = 0; iter < N; iter++) {
        bool updated = false;
        for (ll v = 1; v <= N; v++) {
            if (dist[v] == INF) continue;
            for (ll i = 0; i < G[v].size(); i++) {
                if (chmin(dist[G[v][i].to], dist[v] + G[v][i].w)) {
                    updated = true;
                }
            }
        }
        if (!updated) break;

        if (iter == N - 1ll && updated) exist_negative_cycle = true;
        
    }

    if (exist_negative_cycle) cout << "Negative Cycle" << endl;
    else {
        for (ll v = 1; v <= N; v++) {
            if(dist[v] < INF) cout << dist[v] << endl;
            else cout << "Not Conncted" << endl;
        }
    }
    return 0;
}