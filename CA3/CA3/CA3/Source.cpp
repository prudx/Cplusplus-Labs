//Daniel Maguire - x00127907
//heapSort is an O(nlogn) time complexity algorithm
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#include "HuffmanTree.h"
using namespace std;


void print(map<char, int> &frequency);
void calculateFrequency(map<char, int> &frequency, ifstream &inputFile);


int main() {
	map<char, int> freq = map <char, int>();

	ifstream inputFile;
	inputFile.open("catext.txt");

	calculateFrequency(freq, inputFile);
	print(freq);

	cout << "\n\nNow we will create our tree...\n\n";

	HuffmanTree tree;
	tree.BuildHuffTree(freq);
	tree.Decode();

	system("pause");
	return 0;
}


void print(map<char, int> &frequency) {
	for (auto element : frequency) {
		cout << "Character: " << element.first << "\t\tFrequency: " << element.second << endl;
	}
}

void calculateFrequency(map<char, int> &frequency, ifstream &inputFile) {
	char ch;
	while (inputFile.get(ch)) {
		if (!frequency.empty()) {
			auto el = frequency.find(ch);
			if (el != frequency.end()) {
				el->second += 1; //here
			}
			frequency.insert(pair<char, int>(ch, 1));
		}
		else {
			frequency.insert(pair<char, int>(ch, 1));
		}
	}
}

