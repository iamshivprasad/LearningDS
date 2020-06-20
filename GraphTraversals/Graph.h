#pragma once

#include <string>
#include <map>
#include <unordered_set>

using namespace std;

class Graph
{
public:
	
	void addEdge(string u, string v);
	void dfs(string s);
	void bfs(string s);
	bool isCycleDFSDirected(string s);
	bool isCycleDFSUndirected(string s);

private:
	void dfsUtil(string s, map<string, bool>& visited);
	bool isCycleDFSUtilForDirected(string s, map<string, bool>& visited, unordered_set<string>& parents);
	bool isCycleDFSUtilForUnDirected(string s, map<string, bool>& visited, string parent);

private:
	std::map<std::string, std::unordered_set<std::string>> adj;
	
};

