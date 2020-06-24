#include<bits/stdc++.h>
using namespace std;
bool BF1(vector<vector<pair<int,int>>> v,int n,int e,int s){
	int d[n];
	int par[n];
	for(int i=0;i<n;i++){
		d[i]=INT_MAX;
		par[i]=-1;
	}
	d[s]=0;
	for(int i=0;i<n-1;i++){
		
		for(int i=0;i<n;i++){
			s=i;
			if(d[s]==INT_MAX) continue;
			for(auto it=v[s].begin();it!=v[s].end();it++){
				if(d[(*it).first]>d[s]+(*it).second){
					d[(*it).first]=d[s]+(*it).second;
				}
			}
		}
	/*	for(int i=0;i<n;i++){
			cout<<d[i]<<" ";
		}
		cout<<endl;*/
		
	}
	int flag=1;
		for(int i=0;i<n;i++){
			s=i;
			if(d[s]==INT_MAX) continue;
			for(auto it=v[s].begin();it!=v[s].end();it++){
				if(d[(*it).first]>d[s]+(*it).second){
					d[(*it).first]=d[s]+(*it).second;
					flag=0;
					return flag;
				}
			}
		}
		return flag;
}
int main(){
	int n,e;
	cin>>n>>e;
	//cout<<n<<" -- "<<e;
	vector<vector<pair<int,int>>> v(n);
	//cout<<"\nok ";
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back(make_pair(y,w));
	}
	if(BF1(v,n,e,1))
		cout<<"-ve edge cycle does not exist ";
	else
		cout<<"-ve edge cycle does exist";
}

