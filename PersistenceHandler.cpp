#include "PersistenceHandler.h"
#include "RecordHandler.h"
#include "SequenceSet.h"
#include "Record.h"
#include "BPlusTree.h"
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <list>
#include <fstream>
#include "utils.h"

using namespace std;

/** 
 * Auxiliar function that gets a record and
 * parses it's state into a csv record.
 *
 * @param a Record object
 * @return a string in csv format
 */
string recordToCSV(Record* record);

/**
 * Auxiliar function to get a double and format
 * it into the used format for latitute and longitude
 * in data set.
 *
 * @param a double value
 * @return a string formated in data set's standard
 */
string doubleToStringThis(double number);

BPlusTree* bufferizeDataSetToTree(string dataSetPath) {
	int sequenceSetIndex = 0;
	const int MAX_BLOCKS = 10;
	const int MAX_SEQUENCE_SETS = 10;
	const int MAX_RECORS_PER_BLOCK = 1000;
	long blocksCounter = 0;
	long recordsCounter = 0;
	BPlusTree* tree = new BPlusTree(true, NULL, INITIAL_TREE_ORDER);
	for(int i = 0; i < 10; i++)
		tree = tree->insert(i, new SequenceSet());
	//cout << "Values: " << tree->getKeys().size() << endl;
	//getchar();
	ifstream inputStream;
	inputStream.open(dataSetPath.c_str());
	SequenceSet* sequenceSet = tree->search(sequenceSetIndex);
	if(inputStream.is_open()) {
		string line;
		while(!inputStream.eof()) {
			getline(inputStream, line);
			if(line == "") {
				getline(inputStream, line);
				if(line == "")
					break;
			}
			sequenceSet->addRecord(csvRecordParser(line));
			recordsCounter++;
			if(recordsCounter == MAX_RECORS_PER_BLOCK) {
				blocksCounter++;
				if(blocksCounter == MAX_BLOCKS) {
					sequenceSetIndex++;
					if(sequenceSetIndex < MAX_SEQUENCE_SETS)
						sequenceSet = tree->search(sequenceSetIndex);
					else
						tree = rebuildTree(tree);
				}
			}
		}
	}
	inputStream.close();
	return tree;
}

SequenceSet* bufferizeDataSet(string dataSetPath) {
	ifstream inputStream;
	inputStream.open(dataSetPath.c_str());
	SequenceSet* sequenceSet = new SequenceSet();
	if(inputStream.is_open()) {
		string line;
		while(!inputStream.eof()) {
			getline(inputStream, line);
			if(line == "") {
				getline(inputStream, line);
				if(line == "")
					break;
			}
			sequenceSet->addRecord(csvRecordParser(line));
		}
	}
	inputStream.close();
	return sequenceSet;
}

void updateDataSet(SequenceSet* sequenceSet, string dataSetPath) {
	ofstream outputStream;
	outputStream.open(dataSetPath.c_str(), std::ofstream::out);
	list<Block*> blockList = sequenceSet->getBlockList();
	for(list<Block*>::iterator i = blockList.begin(); i != blockList.end(); i++) {
		Block* block = (*i);	
		set<Record*> recordsSet = block->getRecordsSet();
		for(set<Record*>::iterator r = recordsSet.begin(); r != recordsSet.end(); r++) {
			Record* record = (*r);
			outputStream << recordToCSV(record) << endl;
		}
	}
	outputStream.close();
}

void appendRecord(Record* record, string dataSetPath) {
	ofstream outputStream;
	outputStream.open(dataSetPath.c_str(), std::ofstream::app);
	outputStream << "\n" + recordToCSV(record);
	outputStream.close();
}

string doubleToStringThis(double number) {
	string numberAsString = string(intToString(number));
	replace(numberAsString.begin(), numberAsString.end(), '.', ',');
	string properFormat = "\"" + numberAsString + "\"";
	return properFormat;
}

string recordToCSV(Record* record) {
	string csv = string(intToString(record->getZipCode()));
	csv += "," + record->getPlaceName();
	csv += "," + record->getState();
	csv += "," + record->getCounty();
	csv += "," + string(doubleToString(record->getLatitude()));
	csv += "," + string(doubleToString(record->getLongitude()));
 	return csv;
}
