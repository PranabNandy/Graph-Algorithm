#include<bits/stdc++.h>
using namespace std;
int flag=1;
static int f=0;
void detect(vector<vector<int>> v,int s,bool vis[],bool rec[]){
	cout<<"s "<<s<<" time : "<<f<<endl;
	vis[s]=true;
	rec[s]=true;
	if(flag==1){
			for(auto it=v[s].begin();it!=v[s].end();it++){
				if(rec[*it]==true ){
					flag=0;
					break;
				}
				else  detect(v,*it,vis,rec);
			}
			rec[s]=false;
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
	}
	bool vis[n+1];
	bool rec[n+1];
	for(int i=1;i<=n;i++) {
		rec[i]=vis[i]=false;
	}
	for(int i=1;i<=n;i++){
			if(vis[i]==false){
				detect(v,i,vis,rec);
				f++;
			}
			
	}

	if(flag==1)
		cout<<"No cycle ";
	else
		cout<<"Cycle exist ";
}
