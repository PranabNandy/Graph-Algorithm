#include<bits/stdc++.h>
using namespace std;
struct comp{
	bool operator() (pair<int,int> &a,pair<int,int> &b){
		return a.second>b.second;
	}
};
void prim(vector<vector<pair<int,int>>> v,int n,int e){
	bool vis[n];
	int  par[n];
	int  wei[n];
	for(int i=0;i<n;i++){
		vis[i]=false;
		par[i]=-1;
		wei[i]=INT_MAX;
	}
	int s=3;
	//vis[s]=true;
	priority_queue<pair<int,int>,vector<pair<int,int>>,comp> p;
	wei[s]=0;
	p.push(make_pair(s,wei[s]));
	par[s]=-1;
	int count=0;
	cout<<"OK man "<<endl;
	int fff;
	cin>>fff;
	while(count!=n-1){
		//int min=INT_MAX,y;
		s=p.top().first;
		p.pop();
		if(vis[s]==true){
			continue;
		}
		vis[s]=true;
		//cout<<"p.top() "<<s<<endl;
		for(auto it=v[s].begin();it!=v[s].end();it++){
			if(vis[(*it).first]==false){
				if(wei[(*it).first]>(*it).second){
					wei[(*it).first]=(*it).second;
					par[(*it).first]=s;
					p.push(make_pair((*it).first,(*it).second));
				}
				
			}
		}
		
		count++;
	}
	for(int i=0;i<n;i++){
		cout<<i<<" --> "<<par[i]<<" "<<wei[i]<<endl;
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	vector<vector<pair<int,int>>> v(n);
	for(int i=1;i<=e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	prim(v,n,e);
	
}
