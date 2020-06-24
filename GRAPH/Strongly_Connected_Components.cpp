#include<bits/stdc++.h>
using namespace std;
vector<int> st;
vector<bool> vis;
vector<vector<int>> v;
void dfs(int i){
	vis[i]=true;
	for(auto it=v[i].begin();it!=v[i].end();it++){
			if(vis[*it]==false)
				dfs(*it);
	}
}
vector<vector<int>> rev(vector<vector<int>>){
	int n=v.size();
	vector<vector<int>> v1(n);
	for(int i=0;i<n;i++){
		for(auto it=v[i].begin();it!=v[i].end();it++){
			v1[*it].push_back(i);
		}
	}
	return v1;
}
void ssci(int i){
	vis[i]=true;
	for(auto it=v[i].begin();it!=v[i].end();it++){
			if(vis[*it]==false){
				
				ssci(*it);
			}
	}
	st.push_back(i);

}
void ssc(int n){
	for(int i=0;i<n;i++){
		if(vis[i]==false)
			ssci(i);
	}
	for(int i=0;i<n;i++)
		cout<<st[i]<<" ";
	vector<vector<int>> v1=rev(v);
//	int n=v.size();
	for(int i=0;i<n;i++) vis[i]=false;
	int count=0;
	for(int i=n-1;i>=0;i--){
		if(vis[i]==false){
				dfs(i);
				count++;
		}
	}
	cout<<"\nNo  of connected components : "<<count;
}
int main(){
	int n,e;
	cin>>n>>e;
	v.resize(n);
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	vis.resize(n);
	for(int i=0;i<n;i++) vis[i]=false;
	ssc(n);
	
}
