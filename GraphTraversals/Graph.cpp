#include "Graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void Graph::addEdge(string u, string v)
{
	adj[u].insert(v);
	adj[v].insert(u);
}

void Graph::dfs(string s)
{
	map<string, bool> visited;
	// only connected components
	dfsUtil(s, visited);
}

void Graph::bfs(string s)
{
	map<string, bool> visited;

	queue<string> q;
	q.push(s);

	while (!q.empty())
	{
		auto t = q.front();
		q.pop();

		cout << t << " ";
		visited[t] = true;

		for (auto e : adj[s])
		{
			if (!visited[e])
			{
				q.push(e);
			}
		}
	}

}

bool Graph::isCycleDFSDirected(string s)
{
	map<string, bool> visited;
	unordered_set<string> parents;

	return isCycleDFSUtilForDirected(s, visited, parents);
}

bool Graph::isCycleDFSUndirected(string s)
{
	map<string, bool> visited;
	unordered_set<string> parents;
	return isCycleDFSUtilForUnDirected(s, visited, parent);
}

void Graph::dfsUtil(string s, map<string, bool>& visited)
{
	visited[s] = true;

	cout << s << " ";

	for (auto e : adj[s])
	{
		if (!visited[e])
		{
			dfsUtil(e, visited);
		}
	}
}

bool Graph::isCycleDFSUtilForDirected(string s, map<string, bool>& visited, unordered_set<string>& parents)
{
	visited[s] = true;

	parents.insert(s);

	for (auto v : adj[s])
	{
		if (!visited[s])
		{
			return isCycleDFSUtilForDirected(v, visited, parents);
		}
		else
		{
			if (parents.find(s) != parents.end())
			{
				return true;
			}
		}
	}

	parents.erase(s);
	return false;
}

bool Graph::isCycleDFSUtilForUnDirected(string s, map<string, bool>& visited, string parent)
{
	visited[s] = true;

	for (auto v : adj[s])
	{
		if (!visited[v])
		{
			return isCycleDFSUtilForUnDirected(v, visited, s);
		}
		else
		{
			if (v != parent)
			{
				return true;
			}
		}
	}

	return false;
}



