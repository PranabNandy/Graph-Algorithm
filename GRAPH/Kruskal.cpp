#include<bits/stdc++.h>
using namespace std;
class KR{
	public:
		int s,d,w;
};

bool comp(KR a,KR b){
	return a.w<b.w;
}
int findPar(int parent[],int v){
	if(parent[v]==v)
		return v;
	return findPar(parent,parent[v]);
}
void kruskal(vector<KR> v,int n,int e){
	sort(v.begin(),v.end(),comp);
	KR output[n-1];
	int parent[n];
	for(int i=0;i<n;i++) {
		parent[i]=i;
		//cout<<i<<"="<<parent[i]<<" ";
	}
//	cout<<endl;
	
	int count=0;
	int i=0;
	while(count!= n-1){
		int source=findPar(parent,v[i].s);
		int dest=findPar(parent,v[i].d);
		if(source!=dest){
			output[count++]=v[i];
			parent[source]=dest;
		}
		i++;
	/*	for(int k=0;k<n;k++) {
			cout<<k<<"="<<parent[k]<<" ";
		}
		cout<<endl;
		int x;
		cout<<"Please press enter ";
		cin>>x;*/
	}
	for(int i=0;i<n-1;i++){
		cout<<output[i].s<<" --> "<<output[i].d<<" = "<<output[i].w<<endl;
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	vector<KR> v;
	cout<<"Enter the edges :"<<endl;
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		KR ob;
		ob.s=x;
		ob.d=y;
		ob.w=w;
		v.push_back(ob);
	}
	cout<<"Let's see "<<endl;
	kruskal(v,n,e);
}
