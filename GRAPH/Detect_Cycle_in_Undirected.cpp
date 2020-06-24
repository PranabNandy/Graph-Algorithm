#include<bits/stdc++.h>
using namespace std;
int flag=1;
void detect(vector<vector<int>> v,int s,int p,bool vis[]){
	cout<<"s "<<s<<" p "<<p<<endl;
	vis[s]=true;
	if(flag==1){
			for(auto it=v[s].begin();it!=v[s].end();it++){
				if(vis[*it]==true && (*it)!=p){
					flag=0;
					break;
				}
				else if(vis[*it]==true && (*it)==p){
					
				}
				else  detect(v,*it,s,vis);
			}
	}

	
}
int main(){
	int n,e;
	cin>>n>>e;
	vector<vector<int>> v(n+1);
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bool vis[n+1];
	for(int i=1;i<=n;i++) vis[i]=false;
	detect(v,1,1,vis);
	if(flag==1)
		cout<<"No cycle ";
	else
		cout<<"Cycle exist ";
}
