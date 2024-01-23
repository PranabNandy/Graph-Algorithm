# Graph-Algorithm 😄
It contains all graph based algorithm

### Simple Unioin Implementation { Union-Find (Disjoint Set Union) }

```
class Solution {
public:
    int parent[100001], Rank[100001]; // make parent and rank array of max size
    int find(int a) // find function used to tell us the parent of the value 'a'
    {
        if(parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    
    void Union(int a, int b) // By union we are making parent 
    {
        a = find(a); // find parent of a
        b = find(b); // find parent of b
        
        if(a == b) // if both parents are equal, simply return
            return;
        
        if(Rank[a] > Rank[b]) // rank of a is larger, so it will become parent
        {
            // a would be parent
            parent[b] = a; 
            Rank[a] += Rank[b]; // a become parent, so increase it's rank
        }
        else
        {
            // b would be parent
            parent[a] = b;
            Rank[b] += Rank[a]; // b become parent, so increase it's rank
        } 
    }
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size(); // extract the size of array
        if(n == 0) return 0; // if length is zero simply return zero
        
        // since our parent and rank are global array so everytime reintiliaze them
        for(int i = 0; i < n; i++) parent[i] = i, Rank[i] = 1;
        
        unordered_map<int, int> mp; // making map
        
        for(int i = 0; i < n; i++) // traverse from the arrat
        {
            // if element is already presnt into the map, just continue
            if(mp.find(arr[i]) != mp.end()) continue;
            
            // if (arr[i] - 1) present in the map, we will perform union
            if(mp.find(arr[i] - 1) != mp.end())
            {
                Union(mp[arr[i] - 1], i);
            }
            
             // also, if (arr[i] - 1) present in the map, we will perform union
            if(mp.find(arr[i] + 1) != mp.end())
            {
                Union(mp[arr[i] + 1], i);
            }
            
             mp[arr[i]] = i;
        }
        
        int ans = 0; // intiliaze ans as zero
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, Rank[i]); // take the largest component
        }
        
        return ans; // finally return ans
    }
};

```
