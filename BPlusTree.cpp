#include "BPlusTree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

BPlusTree::BPlusTree(int orderFactor) {
	if(orderFactor < 2)
		throw std::invalid_argument("Minimum orderFactor is 2");
	this->orderFactor = orderFactor;
	//root = new LeafNode();
}

//BPlusTree::~BPlusTree() {}

