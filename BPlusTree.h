#pragma once
#ifndef _B_PLUS_TREE_H_
#define _B_PLUS_TREE_H_

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <cassert>
#include "SequenceSet.h"

class BPlusTree {
private:
	int maxSize;
	bool isLeaf;
	BPlusTree* parent;
	std::vector<int> keys;
	std::vector<BPlusTree*> children;
	std::vector<SequenceSet*> values;

	BPlusTree* split();
	// ---------------------------------------
	BPlusTree* bm();

	BPlusTree* borrow_left(BPlusTree* &left, const size_t& parent_pos);
	BPlusTree* merge_left(BPlusTree* & left, const size_t& parent_pos);
	
	BPlusTree* borrow_right(BPlusTree* &right, const size_t& parent_pos);
	BPlusTree* merge_right(BPlusTree* & right, const size_t& parent_pos);
	// ---------------------------------------
	size_t find_pos(const int&);
	size_t find_pos(const int&)const;

	void remove(const size_t& pos);

public:
	BPlusTree(const bool& isleaf = true, BPlusTree* p = NULL,const int& size = 3);
	BPlusTree(const bool& isleaf = true, const int& size = 3);
	BPlusTree(const BPlusTree&);
	BPlusTree& operator=(const BPlusTree&);
	~BPlusTree();

	void set_parent(BPlusTree* p);

	void set_max_size(const int &);

	int getSize() {
		return maxSize;
	}

	SequenceSet* leftest();

	//int predecessor(const int&);
	int successor(const int&);

	bool find(const int& key) const;
	// can be modified
	// return  > value <
	SequenceSet* search(const int& key);

	BPlusTree* insert(const int& key, SequenceSet* value);

	BPlusTree* del(const int& key);

	bool empty();

	BPlusTree* only_child();

	std::string toString();

	std::vector<int> getKeys() {
		return keys;
	}

	friend BPlusTree* inherit(BPlusTree* &_root);

	friend BPlusTree* rebuildTree(BPlusTree* prevTree);
};

#endif
