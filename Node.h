#ifndef NODE_H
#define NODE_H

#include <list>
#include "utils.h"
#include "SequenceSet.h"
#include <string>

using namespace std;

class Node {
private:
	list<long> keys;
	list<SequenceSet*> pointers;
	Node* next;
	Node* prev;
	bool isLeaf;
	int nodeSize;

public:	

	Node(int nodeSize, bool isLeaf) {
		this->nodeSize = nodeSize;
		this->isLeaf;
	}

	std::list<long> getKeys() {
		return keys;
	}

	void setKeys(std::list<long> keys) {
		this->keys = keys;
	}

	std::list<SequenceSet*> getPointers() {
		return pointers;
	}

	void setPointers(std::list<SequenceSet*> pointers) {
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
