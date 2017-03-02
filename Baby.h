#pragma once
#include <string>

using namespace std;

class Baby {
public:
	Baby() {  
	};

	Baby(string s, int w) {
		name = s;
		weight = w;
	}

	Baby & operator=(Baby & b) 
	{
		name = b.getName();
		weight = b.getWeight();
		return *this;
	}


	int getWeight() {
		return weight;
	}


	const string & getName() {
		return name;
	}

private:
	string name;
	int weight;
	friend class MedicalRecord;
};
