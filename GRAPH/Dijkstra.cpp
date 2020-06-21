#include<bits/stdc++.h>
using namespace std;
void init(){
	cout<<"You are in Init "<<endl;
}
int minDis(int dis[],bool vis[],int n){
	int index=-1;
	for(int i=0;i<n;i++){

		if(vis[i]==false && (index==-1 || dis[i]<dis[index]))
			index=i;	
	}
	return index;
}
struct comp{
	bool operator()(pair<int,int> &a,pair<int,int> &b){
		return a.first>b.first;
	}
};
void dijkstra(vector<vector<pair<int,int>>> v,int s){
	int n=v.size();
	bool vis[n];
	int dis[n];
	dis[s]=0;
	priority_queue<pair<int,int> ,vector<pair<int,int>>,comp> p;
	for(int i=0;i<n;i++){
		vis[i]=false;
		if(s!=i)
		dis[i]=INT_MAX;
		p.push(make_pair(dis[i],i));
	}
	dis[s]=0;
	//p.push(make_pair(dis[s],s));
	for(int i=0;i<n-1;i++){
		int index=p.top().second;
		int sum=p.top().first;
		p.pop();
	//	cout<<"Yes "<<index<<endl;
	/*	if(index==4){
			for(int k=0;k<n;k++){
				cout<<vis[k]<<" && "<<dis[k]<<"		";
			}
		}*/
		for( auto it=v[index].begin() ; it!=v[index].end();it++){
			int x=(*it).first;
			int w=(*it).second;
			int dist=sum+w;
			if(dis[x]>dist){
				dis[x]=dist;
				p.push(make_pair(dis[x],x));
			}
				
		}
	//	cout<<"ok "<<endl;
		vis[index]=true;
	}
	cout<<"After applying dijkstra algo "<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<" -> "<<dis[i]<<endl;
	}
	
}
int main(){
	int n,e;
	cin>>n>>e;
	vector<vector<pair<int,int>>> v(n);
	while(e--){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back(make_pair(y,w));
	}
	dijkstra(v,0);
}
