#ifndef NODE_H
#define NODE_H

#include <vector>
#include "utils.h"
#include "SequenceSet.h"
#include <string>

using namespace std;

class Node {
private:
	vector<long> keys;
	vector<SequenceSet*> pointers;
	Node* next;
	Node* prev;
	bool isLeaf;
	int nodeSize;

public:	

	Node(int nodeSize, bool isLeaf) {
		this->nodeSize = nodeSize;
		this->isLeaf;
	}

	std::vector<long> getKeys() {
		return keys;
	}

	void setKeys(std::vector<long> keys) {
		this->keys = keys;
	}

	std::vector<SequenceSet*> getPointers() {
		return pointers;
	}

	void setPointers(std::vector<SequenceSet*> pointers) {
		this->pointers = pointers;
	}

	Node* getNext() {
		return next;
	}

	void setNext(Node* next) {
		this->next = next;
	}

	Node* getPrev() {
		return prev;
	}

	void setPrev(Node* prev) {
		this->prev = prev;
	}

	bool isLeaft() {
		return isLeaf;
	}

	void setLeaf(bool isLeaf) {
		this->isLeaf = isLeaf;
	}

	int getNodeSize() {
		return nodeSize;
	}

	void setNodeSize(int nodeSize) {
		this->nodeSize = nodeSize;
	}
};

#endif
