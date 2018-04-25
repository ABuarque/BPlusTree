#include "App.h"
#include "RecordHandler.h"
#include "Record.h"

#include "BPlusTree.h"

#include <list>

//BPlusTree* b = new BPlusTree();
//InnerNode* innerNode = new InnerNode();


using namespace std;

int main() {
	//sequenceSetEntryPoint();
	//cleanDataSet("data_set.csv", "proper_data_set.csv");
	

	list<long> l;
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	//cout << *(l.begin()) << endl;

	l.push_front(505);

	//cout << *(l.begin()) << endl;

	for(int i = 0; i < l.size(); i++) {
		long d = *(next(l.begin(), i));

		//cout << d << endl;
	}


	l.insert(next(l.begin(), 2), 90);

	for(int i = 0; i < l.size(); i++) {
		long d = *(next(l.begin(), i));

		cout << d << endl;
	}

	return 0;	

}
