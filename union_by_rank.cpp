#include<bits/stdc++.h>

using namespace std;
vector<int> arr;
class Node{
public:
	int rank;
	int data;
	Node *par;
};
unordered_map<int ,Node*> um;

//initialize the every disjoint set
void make_set(int p){
	Node *n=new Node;
	n->rank=0;
	n->data=p;
	n->par=nullptr;
	um[p]=n;
}


// find by path compression
int find(int a){
	if(um[a]->par==nullptr){
		return a;
	}
	Node *n=um[a];
	Node *n2=n->par;
	int b=find(n2->data);

	um[a]->par=um[b];
	return b;
}


//union_by_rank 
int Union(int a,int b){
	int c=find(a);
	int d=find(b);

	if(c==d){
		return 1;

	}
	int c1=um[c]->rank,d1=um[d]->rank;


	int c2=abs(c1),d2=abs(d1);
	//cout<<"c1 "<<c1<<" d1 "<<d1<<endl;
	if((c2>=d2)){
		
		int val=max(um[c]->rank,um[d]->rank+1);
		um[c]->rank=val;
		um[d]->par=um[c];
	}
	else{
		um[d]->rank=max(um[d]->rank,um[c]->rank+1);
		um[c]->par=um[d];

	}

	return 0;

}
void print(int a){
	Node *n=um[a];

	cout<<"Data : "<<n->data<<" Rank : "<<n->rank<<" par : "<<n->par<<endl;
}
int main(){


	int n=8;
	for(int i=1;i<=n;i++)
		make_set(i);

	for(int i=1;i<=n;i++)
		print(i);

	cout<<"First "<<find(5)<<endl;
	cout<<"First "<<find(2)<<endl;

	for(int i=1;i<=15;i++){
		int first,second;
		cin>>first>>second;
		if(Union(first,second))
			cout<<"<----- Forms a Loop ------>"<<endl;
		//for(int i=1;i<=n;i++) print(i);
	}

	return 0;

}