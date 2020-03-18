// topological sort
#include<bits/stdc++.h>
using namespace std;
#define MAXN 15
vector<int> adjList[MAXN];
int inDegree[MAXN];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> result;

void kahn(int n){
	for(int i=1; i<=n; i++){
		for(auto j: adjList[i]) inDegree[j]++;
	}
	
	for(int i=1; i<=n; i++) if(inDegree[i]==0) pq.push(i);
	
	while(pq.empty()==false){
		int node = pq.top();
		result.push_back(node);
		pq.pop();
		for(auto i: adjList[node]){
			inDegree[i]--; 
			if(inDegree[i]==0) pq.push(i);
		}
	}	 
	
	return ;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adjList[x].push_back(y);
	}
	
	kahn(n);
	
	for(int i=0; i<result.size(); i++) printf("%d ",result[i]);
	return 0;
}
