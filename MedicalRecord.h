#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;




class MedicalRecord {
public:

	MedicalRecord() {
		babies = new Baby[1000000];	
		numofbabies = 0;	

	}

	
	~MedicalRecord() {
		delete[] babies;	
	}

	
	void buildMedicalRecordfromDatafile(string filename) {		
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	string mostPopularName() {		
									
		string names[1000];	
		for (int i = 0; i < 1000; i++) 
		{
			names[i] = "_";
		}

		cout << "Making the names array." << endl;	
		int inc = 0;	
		int totNames = 0;	
		for (int i = 0; i < numofbabies; i++)
		{
			for (int x = 0; x < 1000; x++)	
			{
				
				
				if (babies[i].name == names[x])
				{
					break; 
						   
				}
				else if (names[x] == "_")
				{
					names[x] = babies[i].getName();	
					totNames++; 
					break;
				}
			}
			inc++;	
			if (inc % 10000 == 0)	
				cout << inc << endl;	
		}
		cout << "Passed making the names array." << endl;	
		int popNameIndex;	
		int popNameCount = 0;	
		inc = 0;		
		for (int i = 0; i < 1000; i++)	
		{
			int currentNum = numberOfBabiesWithName(names[i]);	
			if (currentNum > popNameCount) 
			{
				popNameIndex = i;	
				popNameCount = currentNum;
			}
			inc++;	
			if (inc % 10 == 0)	
				cout << inc << endl;	 
		}
		return names[popNameIndex];	
									
	}

	
	int numberOfBirths() {
		return numofbabies;	
	}


	int numberOfBabiesWithLowBirthWeight() {
		int lowWeightCount = 0;	
		for (int i = 0; i < numofbabies; i++)	
		{
			if (babies[i].getWeight() < 2500)
				lowWeightCount++;
		}
		return lowWeightCount;	
	}


	int numberOfBabiesWithName(string s) {					
		int numBabiesWithName = 0;				
		for (int i = 0; i < numofbabies; i++)			
		{
			if (babies[i].getName() == s)
				numBabiesWithName++;
		}
		return numBabiesWithName;
	}

private:

	void addEntry(Baby b) {		
		babies[numofbabies] = b;	
		numofbabies++;				
	}

	
	Baby * babies;	
	int numofbabies;			

};
