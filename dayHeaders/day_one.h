#pragma once
#include "../basics.h"
namespace day_one {
	int findSumOfNumbers(const string& filename) {
		ifstream fileInputStream(filename);
		string line;
		int sum = 0;
		while (getline(fileInputStream, line))
		{
			smatch match;
			regex reg(R"(\d)");
			regex_search(line, match, reg);
			int first = stoi(match.str());
			reverse(begin(line), end(line));
			regex_search(line, match, reg);
			int last = stoi(match.str());
			cout << "first: " << first << ", last: " << last << endl;
			sum += first * 10 + last;
		}
		return sum;
	}
}