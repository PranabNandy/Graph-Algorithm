#include<bits/stdc++.h>
using namespace std;
class Graph{
	public:
		int v;
		vector<int> *g;
		Graph(int v){
			this->v=v;
			g=new vector<int>[v];
		}
		void addEdge(int v,int u){
			g[v].push_back(u);
		}
};
void dfs(int s,bool *vis,Graph *ob){
	if(vis[s]==false)
		cout<<s<<"--> ";
	vis[s]=true;
	
	for(auto it=ob->g[s].begin();it!=ob->g[s].end();it++){
		if(vis[*it]==false)
			dfs(*it,vis,ob);
			
	}
}
void dft(Graph *ob){
	bool *vis=new bool[ob->v];
	for(int i=0;i<ob->v;i++)
		vis[i]=false;
	for(int i=0;i<ob->v;i++){
		dfs(i,vis,ob);
		cout<<endl;
		//cout<<"Ok ";
	}
}
int main(){
	Graph *ob=new Graph(5);
	ob->addEdge(0,1);
	ob->addEdge(1,4);
	ob->addEdge(1,2);
	ob->addEdge(0,2);
	ob->addEdge(3,0);
	cout<<"DFT of the given graph : "<<endl;
	dft(ob);
}
