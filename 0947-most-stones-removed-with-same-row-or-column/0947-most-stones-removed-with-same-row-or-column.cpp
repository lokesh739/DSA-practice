class DisjointSet {
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findultimateparent(int x){
        if(x==parent[x]) return x;
        return parent[x]=findultimateparent(parent[x]);
    }

    bool find(int u, int v) {
        if(findultimateparent(u)==findultimateparent(v)){
            return true;
        }
        return false;
    }

    void unionByRank(int u, int v) {
        int ulu=findultimateparent(u);
        int ulv=findultimateparent(v);
        if(ulu==ulv) return;
        if(rank[ulu]<rank[ulv]){
            parent[ulu]=ulv;
        }
        else if(rank[ulv]<rank[ulu]){
            parent[ulv]=ulu;
        }
        else{
            parent[ulu]=ulv;
            rank[ulv]++;
        }
    }

    void unionBySize(int u, int v) {
       int ulu=findultimateparent(u);
       int ulv=findultimateparent(v);
       if(ulu==ulv) return;
       if(size[ulu]<size[ulv]){
        parent[ulu]=ulv;
        size[ulv]+=size[ulu];
       }
       else{
        parent[ulv]=ulu;
        size[ulu]+=size[ulv];
       }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }

        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int> stonenode;
        for(auto it:stones){
            int adjrow=it[0];
            int adjcol=it[1];
            ds.unionByRank(adjrow,adjcol);
            stonenode[adjrow]=1;
            stonenode[adjcol]=1;
        }

        int count=0;
        for(auto it:stonenode){
            if(ds.findultimateparent(it.first)==it.first){
                count++;
            }
        }
        return n-count;
    }
};