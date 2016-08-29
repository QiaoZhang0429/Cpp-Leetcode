/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], returntrue.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], returnfalse.

Hint:

Given n = 5 andedges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected byexactly one path. In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
class DisjointSet{//array
private:
    int size;
    int count;
    vector<int> dSet;
public:
    DisjointSet(int n){
        size = n;
        count = n;
        for(int i = 0; i < size; i++)
            dSet.push_back(i);
    }
    bool union(int a, int b){
        int root1 = find(a);
        int root2 = find(b);
        if(root1 == root2)
            return false;
        for(int i = 0; i < size; i++){
            if(dSet[i] == root1)
                dSet[i] = root2;
        }
        count--;
        return true;
    }
    void find(int a){
        return dSet[a];
    }
    int getCount(){
        return count;
    }
};
class Solution {  
public:  
    bool validTree(int n, vector<pair<int, int>>& edges) {  
        DisjointSet ds(n);
        for(auto e:edges){
            if(!ds.union(e.first, e.second))
                return false;
        } 
        return ds.getCount() == 1;
    }  
       
};  