#pragma once

#include <unordered_map>

struct Node
{
	int key;
	int val;

	Node* next;
	Node* prev;

public:
	Node() : next(nullptr), prev(nullptr) {}
};

class LRUCache
{
private:

	int m_capacity;
	std::unordered_map<int, Node*> m_table;

	Node* m_head = nullptr;
	Node* m_tail = nullptr;

public:

	LRUCache(int size);
	~LRUCache();
m
	int get(int key);
	void put(int key, int val);

private:
	void add(Node* node);

	LRUCache(const LRUCache&) = delete;
	LRUCache& operator=(LRUCache&) = delete;
};

