#ifndef NODE_H
#define NODE_H

#include <vector>
#include "utils.h"
#include "SequenceSet.h"
#include <string>
/*
class Node {
protected:
	std::vector<long> keys;

public:

	Node();

	virtual ~Node();

	int keysSize();

	virtual SequenceSet* getSequenceSet(long key) = 0;

	virtual void deleteSequenceSet(long key) = 0;

	virtual void insertSequenceSet(long key, SequenceSet* sequenceSet) = 0;

	virtual SequenceSet* getFirstLeafKey() = 0;

	virtual std::vector<SequenceSet*> getRange(long key1, RangePolicy policy1, 
									   long key2, RangePolicy policy2) = 0;	

	virtual void merge(Node* sibilingNode) = 0;

	virtual Node* split() = 0;

	virtual bool isOverFlow() = 0;

	virtual bool isUnderFlow() = 0;

	std::string toString();
};
*/
#endif
