#include "LRUCache.h"

LRUCache::LRUCache(int size) : m_capacity(size)
{
}

LRUCache::~LRUCache()
{
	// clean up the linked list nodes
}

int LRUCache::get(int key)
{
	auto itr = m_table.find(key);
	if (itr == m_table.end())
		return -1;

	int ret = itr->second->val;

	Node* prev = itr->second->prev;
	Node* next = itr->second->next;

	prev->next = next;

	if (itr->second != m_tail)
		next->prev = prev;
	else
		m_tail = prev;

	add(itr->second);
	
	return ret;
}

void LRUCache::put(int key, int val)
{
	// found node for the given key
	auto itr = m_table.find(key);
	if (itr != m_table.end())
	{
		Node* prev = itr->second->prev;
		Node* next = itr->second->next;

		prev->next = next;

		if(itr->second != m_tail)
			next->prev = prev;
		else
			m_tail = prev;

		itr->second->val = val;
		add(itr->second);
	}
	else
	{
		if (m_table.size == m_capacity)
		{
			m_table.erase(key);

			// delete from tail
			Node* prevToTail = m_tail->prev;
			delete m_tail;
			m_tail = nullptr;
			m_tail = prevToTail;
		}

		Node* newNode = new Node();
		newNode->key = key;
		newNode->val = val;

		add(newNode);

		m_table.insert(std::make_pair(key, newNode));
	}
}

void LRUCache::add(Node* node)
{
	node->next = m_head;
	m_head->prev = node;
	m_head = node;
}


