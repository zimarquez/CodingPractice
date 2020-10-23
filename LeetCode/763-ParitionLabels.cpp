#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> partitionLabels(string S) {
        
        if (S.size() <= 1) return vector<int>(1);
        
        int leftIndex = 0;
        char left = S[leftIndex];
        vector<int> partitions;
        
        for (int i=S.size()-1; i <= leftIndex; i--) {
            /*if (i == leftIndex) {
	    	partitions.push_back(i - leftIndex + 1);
            }*/
	    if (S[i] == left) {
                partitions.push_back(i - leftIndex + 1);
                leftIndex = i+1;
                left = S[leftIndex];
                i = S.size()-1;
            }
        }
        return partitions;
}

void printVector(vector<int> res) {
	for (auto value : res) {
		cout << value << "   ";
	}
	cout << endl;
}

int main() {

	string S = "ababcbacadefegdehijhklij";
	vector<int> res = partitionLabels(S);
	printVector(res);

	return 0;
}
