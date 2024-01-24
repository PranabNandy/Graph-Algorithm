# Graph-Algorithm 😄
It contains all graph based algorithm

### Simple Unioin Implementation { Union-Find (Disjoint Set Union) }
![Screenshot from 2024-01-24 11-37-11](https://github.com/PranabNandy/Graph-Algorithm/assets/34576104/8e2f93bf-83c8-4045-b5b7-ec76c14e7115)

```
class Solution {
private:
    vector<int> parent, Rank;
    int find(int a){
        if(parent[a]==a) return parent[a];
        else return parent[a] = find(parent[a]);
    }
    void Union(int a,int b){
        int par_a=find(a);
        int par_b=find(b);
        if(par_a==par_b) return;
        if(Rank[par_a]>Rank[par_b]){
            parent[par_b]=par_a;
            Rank[par_a]+=Rank[par_b];
        }
        else{
            parent[par_a]=par_b;
            Rank[par_b]+=Rank[par_a];
        }
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        parent.clear(); parent.resize(n+1);
        Rank.clear(); Rank.resize(n+1);
        unordered_map<int,int> Hash;
        Hash.clear();
        int ans=0;

        for(int i=0;i<n;i++){
            parent[i]=i; Rank[i]=1;
        }
        for(int i=0;i<n;i++){
            if(Hash.count(nums[i])) continue;

            if(Hash.count(nums[i]+1)) Union(i,Hash[nums[i]+1]);        
            if(Hash.count(nums[i]-1)) Union(i,Hash[nums[i]-1]);
    
            Hash[nums[i]]=i;
        }
        for(int i=0;i<n;i++) ans=max(ans,Rank[i]);
        return ans;
    }
};

```
