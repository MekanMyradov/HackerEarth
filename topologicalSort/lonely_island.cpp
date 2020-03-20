#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e5 +2)
vector<int> adjList[2*MAXN];
queue<int> q;
double prob[2*MAXN];
#define e (double)(1e-9)
int inDegree[2*MAXN];
double outDegree[2*MAXN];

double absol(double a, double b){
	double tmp = a-b;
	if(tmp < 0.00) return tmp*(-1.00);
	return tmp;
}

void kahn(int n, int start){
	
	for(int i=1; i<=n; i++) if(inDegree[i]==0) q.push(i);
	prob[start] = 1.00;
//bfs	
	while(q.empty()==false){
		int v = q.front();
		q.pop();
		for(auto i: adjList[v]){
			inDegree[i]--;
			if(inDegree[i]==0) q.push(i);
			prob[i] += prob[v]/outDegree[v];
		}
	}
double maxx = -2.40;

	for(int i=1; i<=n; i++) if(outDegree[i]==0 && prob[i] > maxx ) maxx = prob[i];
	for(int i=1; i<=n; i++) if(outDegree[i]==0 && absol(maxx, prob[i]) <= e) printf("%d ",i);

	return;
}

int main(){
	int n,m,r;
	assert(scanf("%d %d %d",&n,&m,&r));
	for(int i=0; i<m; i++){
		int a,b;
		assert(scanf("%d %d",&a,&b));
		assert(a!=b);
		adjList[a].push_back(b);		
		inDegree[b]++;
		outDegree[a]+=1.00;
	}
	
	kahn(n, r);
	
	return 0;
}
