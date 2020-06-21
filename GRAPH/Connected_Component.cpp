#include<bits\stdc++.h>
using namespace std;
void dfs(int s,list<int> *l,bool *vis){
	if(vis[s]==false){
		cout<<s<<"->";
	}
	vis[s]=true;
	for(auto it=l[s].begin();it!=l[s].end();it++){
		if(vis[*it]==false)
			dfs(*it,l,vis);
	}	
}
void connectedComponent(list<int> *l,int n){
	int len=n;
	bool *vis=new bool[len];
	for(int i=0;i<len;i++) vis[i]=false;
	int count=0;
	for(int i=0;i<len;i++){
		if(vis[i]==false){
			dfs(i,l,vis);
			cout<<endl;
			count++;
		}
		
	}
	cout<<"No of connected components are "<<count;
}
int main(){
	int n,e;
	cin>>n>>e;
	
	list<int> *l=new list<int>[n];
	while(e--){
		int x,y;
		cin>>x>>y;
		l[x].push_back(y);
		l[y].push_back(x);
	}
	connectedComponent(l,n);
}
