
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

vector<int> djikstra(int source, vector<vector<iPair>>& Graph, int n) {
    vector<int> distArr(n, INT_MAX);
    priority_queue<iPair, vector<iPair>, greater<iPair>> Heap;

    distArr[source - 1] = 0;
    Heap.push(make_pair(0, source));

    while (!Heap.empty()) {
        int u = Heap.top().second;
        Heap.pop();

        for (auto it = Graph[u - 1].begin(); it != Graph[u - 1].end(); it++) {
            int v = it->first;
            int weight = it->second;

            if (distArr[u - 1] != INT_MAX && distArr[u - 1] + weight < distArr[v - 1]) {
                distArr[v - 1] = distArr[u - 1] + weight;
                Heap.push(make_pair(distArr[v - 1], v));
            }
        }
    }

    return distArr;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << "Nodes: " << n << " Edges: " << m << endl;
    vector<vector<iPair>> Graph(n);

    for (int i = 0; i < m; i++) {
        int x1, x2, w;
        cin >> x1 >> x2 >> w;
        Graph[x1 - 1].push_back(make_pair(x2, w));
    }

    int src;
    cout << "Source for Djikstra:";
    cin >> src;

    vector<int> DistArr = djikstra(src, Graph, n);

    int dest;
    cout << "Destination:";
    cin >> dest;

    cout << "Shortest distance from " << src << " to " << dest << " is " << DistArr[dest - 1] << endl;
}
