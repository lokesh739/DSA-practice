class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int drow[4]={1,0,-1,0};
                int dcol[4]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        int node=row*n+col;
                        int adjnode=nrow*n+ncol;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
        }

        int maxcount=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int drow[4]={1,0,-1,0};
                int dcol[4]={0,1,0,-1};
                set<int> components;
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        components.insert(ds.findultimateparent(nrow*n+ncol));
                    }
                }
                int sizetotal=0;
                for(auto it:components){
                    sizetotal+=ds.size[it];
                }
                maxcount=max(maxcount,sizetotal+1);
            }
        }
        for(int cell=0;cell<n*n;cell++){
            maxcount=max(maxcount,ds.size[ds.findultimateparent(cell)]);
        }
        return maxcount;

    }
};