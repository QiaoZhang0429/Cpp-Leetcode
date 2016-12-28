vector<int> findPath(vector<pair<int, int>>& graph, int u, int v){
	vector<int> path;	
	unordered_map<int, vector<int>> adjList;
	unordered_set<int> visited;

	for(auto e:graph){//DAG
		adjList[e.first].push_back(e.second);
	}

	dfs(adjList, visited, u, v, path);

	return rslt;
}

void dfs(unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, int u, int v, std::vector<int>& path){
	if(u == v){
		path.push_back(u);
		//print path
		path.pop_back();
		return ;
	}
	if(visited.find(v) != visited.end())
		return ;
	visited.insert(u);
	path.push_back(u);
	for(auto w:adjList[u])
		dfs(adjList, visited, w, v, path);
	path.pop_back();
}