#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 8;

vector<int> adj[N];
vector<bool> visited;
vector<int> dist;

const int INF = 1e9;

void bfs(int u){
    dist.assign(N, INF);

    queue<int> q;

    q.push(u);

    dist[u] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        cout << v << " ";

        for(auto e : adj[v]){
            if(dist[e] == INF){
                dist[e] = dist[v] +1;
                q.push(e);
            }
        }
    }
}

int main(){
    visited.assign(N, false);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(6);
    adj[2].push_back(5);
    adj[5].push_back(7);
    bfs(0);

    cout << "\n";

    return 0;
}