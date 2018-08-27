// Carrioli Damiano 9032-2614-65
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// Please fill in your USC username
const string USCusername = "Carrioli";

int stealingGold(vector<int> w) {
	int length = w.size();
	int* x = new int[length];
	bool stealing_last_cave = false;

	int sol1 = 0;
	int sol2 = 0;

	// trivial cases
	if (length == 1) return w[0];
	else if (length == 2) {
		if (w[0] > w[1]) return w[0];
		return w[1];
	} else {


		// option 1: steal first cave, don't steal last
		x[length - 1] = w[length - 1];
		if (w[length - 2] > w[length - 1]) x[length - 2] = w[length - 2];
		else x[length - 2] = w[length - 1];

		for (int i = length - 3; i > 0; i--) {
			if (w[i] + x[i + 2] > x[i + 1]) x[i] = w[i] + x[i + 2];
			else x[i] = x[i + 1];
		}
		sol1 = x[1];

		// option 2: don't steal first cave
		x[length - 2] = w[length - 2];
		if (w[length - 3] > w[length - 2]) x[length - 3] = w[length - 3];
		else x[length - 3] = w[length - 2];

		for (int i = length - 4; i >= 0; i--) {
			if (w[i] + x[i + 2] > x[i + 1]) x[i] = w[i] + x[i + 2];
			else x[i] = x[i + 1];
		}
		sol2 = x[0];

		delete[] x;
		x = NULL;


		if (sol1 > sol2) return sol1;
		return sol2;
	}
	
}

// DO NOT MODIFY THE FOLLOWING

int main()
{
	vector<int> gold;
	int curr;
	while (cin >> curr) {
		gold.push_back(curr);
	}
	int answer = stealingGold(gold);
	ofstream out;
	out.open((USCusername + ".txt").c_str(), ios::app);
	out << answer << endl;
	return 0;
}