#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<int> minHenchmen;
vector<int> maxHenchmen;

int preliminaryChecks(int numLambs)
{
	if (numLambs == 1)
	{
		minHenchmen.push_back(1);
		maxHenchmen.push_back(1);
		return numLambs-1;
	}
	else if (numLambs == 2)
	{
		minHenchmen.push_back(1);
		minHenchmen.push_back(1);

		maxHenchmen.push_back(1);
		maxHenchmen.push_back(1);
		return numLambs-2;
	}
	else
	{
		minHenchmen.push_back(1);
		minHenchmen.push_back(2);

		maxHenchmen.push_back(1);
		maxHenchmen.push_back(1);
		return numLambs-3;
	}
}

int getMinLAMBS(vector<int> henchmen)
{
	return henchmen.back() + henchmen.at(henchmen.size()-2);
}

int getMaxLAMBS(vector<int> henchmen)
{
	return 2*henchmen.back();
}

void generous(int numLambs)
{
	int remainder = numLambs - 3;	// account for the 3 LAMBS used in preliminary check
	int minLAMBS = getMinLAMBS(minHenchmen);
	int maxLAMBS = getMaxLAMBS(minHenchmen);

	while (remainder >= minLAMBS)
	{
		minLAMBS = getMinLAMBS(minHenchmen);
		maxLAMBS = getMaxLAMBS(minHenchmen);

		printf("remainder: %d\n", remainder);

		if (remainder < maxLAMBS)
		{ 
			minHenchmen.push_back(remainder);
			remainder -= remainder;
		}
		else
		{
			minHenchmen.push_back(maxLAMBS);
			remainder -= maxLAMBS;
		}
		minLAMBS = getMinLAMBS(minHenchmen);
		cout << minLAMBS << " - " << minHenchmen.back() << " - " << maxLAMBS << endl;
	}
	printf("remainder: %d\n", remainder);
}

void greedy(int numLambs)
{
	int remainder = numLambs - 2;	// account for the 2 LAMBS used in preliminary check
	int minLAMBS = getMinLAMBS(maxHenchmen);
	int maxLAMBS = getMaxLAMBS(maxHenchmen);

	cout << "greedy" << endl;
	while (remainder >= minLAMBS)
	{
		minLAMBS = getMinLAMBS(maxHenchmen);
		maxLAMBS = getMaxLAMBS(maxHenchmen);
		
		maxHenchmen.push_back(minLAMBS);
		remainder -= minLAMBS;

		minLAMBS = getMinLAMBS(maxHenchmen);
		cout << minLAMBS << " - " << maxHenchmen.back() << " - " << maxLAMBS << endl;
	}
}

void printVect(vector<int> v)
{
	for (int i=v.size()-1; i>=0; i--)
	{
		printf("H[%d] = %d\n", i, v[i]); 
	}
}

int main (void) 
{
	printf("**************************\n");
	printf("**  Lovely Lucky Lambs  **\n");
	printf("**************************\n");

	int numLambs;
	printf("Enter a positive int: ");
	cin >> numLambs;

	int remainder = preliminaryChecks(numLambs);
	if (remainder != 0) {
		generous(numLambs);
		greedy(numLambs);
	}

	int result = maxHenchmen.size() - minHenchmen.size();

	printf("\nResult: %d\n\n", result);

	cout << "--Generous--" << endl;
	printVect(minHenchmen);

	cout << "--Greedy--" << endl;
	printVect(maxHenchmen);

	return 0;	
}
