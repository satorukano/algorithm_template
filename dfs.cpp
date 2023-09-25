#include<iostream>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(Graph &G, int v, vector<bool> &seen) {
    seen[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (seen[G[v][i]]) continue;
        dfs(G, G[v][i], seen);
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> seen(N+1, false);
    Graph G(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(G, 1, seen);
    for (int i = 1; i < N + 1; i++ ) {
        if (!seen[i]) {
            cout << "The graph is not connected." << endl;
            return 0;
        }
    }
    cout << "The graph is connected." << endl;

    return 0;
}