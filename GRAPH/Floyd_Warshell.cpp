#include<bits/stdc++.h>
using namespace std;
int N=0;
void Floyd(vector<vector<int>> g,int n){
	int dp[n][n];
	memset(dp,INT_MAX,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				dp[i][i]=0;
			else
				dp[i][j]=g[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX){
					
				}
				if(dp[i][j]>dp[i][k]+dp[k][j])
					dp[i][j]=dp[i][k] + dp[k][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	N=n;
	int g[n][n];
	vector<vector<int>> v(n);
	for(int i=0;i<n;i++)
		v[i].resize(n);
//	memset(g,INT_MAX+1,sizeof(g));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			g[i][j]=INT_MAX;
			cout<<g[i][j]<<" ";
		}
			
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) v[i][j]=0;
			else v[i][j]=g[i][j];
		}
			
	}
		
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		v[x][y]=w;
		v[y][x]=w;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	Floyd(v,n);
}
