vector<int> topologicalSort(vector<pair<int, int>>& graph, int numV){
	vector<int> rslt;	
	vector<int> inDegree(numV, 0);
	unordered_map<int, vector<int>> adjList;
	unordered_set<int> visited;

	for(auto e:graph){
		inDegree[e.second]++;
		adjList[e.first].push_back(e.second);
	}

	for(int k = 0; k < numV; k++){
		int vertex = -1;
		for(int i = 0; i < inDegree.size(); i++)
			if(visited.find(i) == visited.end() && inDegree[i] == 0){
				vertex = i;
				break;
			}
		if(vertex == -1)
			cout << "The graph contains a circle." << endl;
		visited.insert(vertex);
		rslt.push_back(vertex);
		for(auto w:adjList[vertex])
			inDegree[w]--;
	}

	return rslt;
}

vector<int> topologicalSort(vector<pair<int, int>>& graph, int numV){
	vector<int> rslt;	
	vector<int> inDegree(numV, 0);
	unordered_map<int, vector<int>> adjList;
	queue<int> q;

	for(auto e:graph){
		inDegree[e.second]++;
		adjList[e.first].push_back(e.second);
	}

	int vertex = -1;
	for(int i = 0; i < inDegree.size(); i++)
		if(inDegree[i] == 0){
			vertex = i;
			break;
		}
	q.push(vertex);

	while(!q.empty()){		
		vertex = q.front();
		q.pop();
		rslt.push_back(vertex);
		for(auto w:adjList[vertex])
			if(--inDegree[w] == 0)
				q.push(w);
	}

	if(rslt.size() < numV)
		cout << "The graph contains a circle." << endl;

	return rslt;
}

bool hasCycle = false;

vector<int> topologicalSort(vector<pair<int, int>>& graph, int numV){
	vector<int> rslt;	
	unordered_map<int, vector<int>> adjList;
	unordered_set<int> visited;
	unordered_set<int> onStack;
	for(int i = 0; i < numV; i++)
		dfs(i, rslt, adjList, visited, onStack);
	reverse(rslt.begin(), rslt.end());
	return hasCycle? vector<int>() : rslt;
}

void dfs(int v, vector<int>& rslt, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, unordered_set<int>& onStack){
	if(hasCycle)
		return ;
	if(visited.find(v) == visited.end()){
		visited.insert(v);
		onStack.insert(v);
		for(auto w:adjList[v])
			dfs(w, rslt, adjList, visited, onStack);
		rslt.push_back(v);
		onStack.erase(v);
	}
	else if(onStack.find(v) != onStack.end())
		hasCycle = true;
}