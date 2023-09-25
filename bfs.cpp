#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using Graph = vector<vector<int>>;

void bfs(Graph &G, int s, vector<int>&dist){
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int next_s = que.front();
        que.pop();
        for (int i = 0; i < G[next_s].size(); i++) {
            if (dist[G[next_s][i]] != -1) continue;
            dist[G[next_s][i]] = dist[next_s] + 1;
            que.push(G[next_s][i]);
        }
    }
    return ;
}
int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(N+1, -1);
    dist[1] = 0;
    bfs(G, 1, dist);

    for (int i = 1; i <= N; i++) {
        cout << dist[i] << endl;
    }
    return 0;
}