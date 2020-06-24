#include<bits/stdc++.h>
using namespace std;
void kahn(vector<vector<int>> v,int in[],int n,int e){
	vector<int> topo;
	deque<int> q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push_back(i);
		}
	}
	while(q.empty()==0){
		int a=q.front();
		topo.push_back(a);
		q.pop_front();
		for(auto it=v[a].begin();it!=v[a].end();it++){
			in[(*it)]--;
			if(in[*it]==0){
				q.push_back(*it);
			}
		}
		for(int i=1;i<=n;i++){
		cout<<in[i]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<topo[i]<<" ";
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	vector<vector<int>> v(n+1);
	int in[n+1];
	for(int i=1;i<=n;i++){
		in[i]=0;
	}
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		in[y]++;
	}
	for(int i=1;i<=n;i++){
		cout<<in[i]<<" ";
	}
	cout<<endl;
	kahn(v,in,n,e);
}
