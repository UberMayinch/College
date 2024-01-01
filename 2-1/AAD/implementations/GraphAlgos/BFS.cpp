#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
	int n, m;
	cin >> n >> m;
	cout << "Vertices:" << n << '\n';
	cout << "Edges:" <<  m << '\n';
	vector <int> Graph[n];
	vector <bool> visited(n,false);
	for(int i=0;i<m;i++){
		int v1, v2;
		cin >> v1 >> v2;
		Graph[v1-1].pb(v2);
	}
	
	int x;
	cin >> x;
	queue<int> q;
	q.push(x);
	cout << "BFS starting at node" << x << '\n';

	while(!q.empty()){
		x = q.front();
		q.pop();
		cout << x << " ";
		visited[x-1]=1;
		for(auto i=Graph[x-1].begin(); i!= Graph[x-1].end(); i++){
			if (!visited[*i-1]){
				q.push(*i);
				visited[*i-1]=true;
			}
		}
	}
	

}
