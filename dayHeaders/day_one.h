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

	int getNumberFromWord(const string& word) {
		if (word == "one") {
			return 1;
		}
		else if (word == "two") {
			return 2;
		}
		else if (word == "three") {
			return 3;
		}
		else if (word == "four") {
			return 4;
		}
		else if (word == "five") {
			return 5;
		}
		else if (word == "six") {
			return 6;
		}
		else if (word == "seven") {
			return 7;
		}
		else if (word == "eight") {
			return 8;
		}
		else if (word == "nine") {
			return 9;
		}
	}

	int findExtendedSumOfNumbers(const string& filename) {
		ifstream fileInputStream(filename);
		string line;
		int sum = 0;
		int first;
		int last;
		while (getline(fileInputStream, line))
		{
			smatch match;
			regex reg(R"(\d|one|two|three|four|five|six|seven|eight|nine)");
			regex_search(line, match, reg);
			string matchStr = match.str();
			regex numReg(R"(\d)");
			if (!regex_search(matchStr, match, numReg)) {
				first=getNumberFromWord(matchStr);
			}
			else {
				first = stoi(matchStr);
			}
			reverse(begin(line), end(line));
			regex reg2(R"(\d|eno|owt|eerht|ruof|evif|xis|neves|thgie|enin)");
			regex_search(line, match, reg2);
			matchStr = match.str();
			if (!regex_search(matchStr, match, numReg)) {
				reverse(begin(matchStr), end(matchStr));
				last = getNumberFromWord(matchStr);
			}
			else {
				last = stoi(matchStr);
			}
			cout << "first: " << first << ", last: " << last << endl;
			sum += first * 10 + last;
		}
		return sum;
	}
}