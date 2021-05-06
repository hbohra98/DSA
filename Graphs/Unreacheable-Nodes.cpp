/*

https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/dfs-3/

You have been given a graph consisting of N nodes and M edges. The nodes in this graph are enumerated from 1 to N . The graph can consist of self-loops as well as multiple edges. This graph consists of a special node called the head node. You need to consider this and the entry point of this graph. You need to find and print the number of nodes that are unreachable from this head node.

Input Format

The first line consists of a 2 integers N and M denoting the number of nodes and edges in this graph. The next M lines consist of 2 integers a and b denoting an undirected edge between node a and b. The next line consists of a single integer x denoting the index of the head node.

*Output Format *:

You need to print a single integer denoting the number of nodes that are unreachable from the given head node.

Sample Input:
10 10
8 1
8 3
7 4
7 5
2 6
10 7
2 8
10 9
2 10
5 10
2

Output:
0

*/
#include <iostream>
#include <vector>

using namespace std;

vector <bool> visited;

void initializeVisited(int n){
	for(int i=0;i<=n;i++){
		visited.push_back(false);
	}
}

void dfs(vector <int> adj[] , int node){
	visited[node] = true;
	for(int i=0;i<adj[node].size();i++){
		if(!visited[adj[node][i]])
			dfs(adj,adj[node][i]);
	}
}

int main(){
	int n , m;
	cin >> n >> m;
	vector <int> adj[n+1];
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int x;
	cin>>x;

	initializeVisited(n);

	dfs(adj,x);
	int count = 0;
	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			count++;
		}
	}
	cout<<count<<endl;

}
