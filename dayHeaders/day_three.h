#pragma once
#include "../basics.h"

namespace day_three {
	/*class blueprintData {
	public:
		blueprintData(char& _char,int x,int y):
			character(_char),
			position(poscoords(x,y)) {}
		bool operator== (blueprintData& other) {
			return character == other.character;
		}
		void operator +(blueprintData& other) {
			number = other.number;
		}
	protected:
		char character;

	private:
		poscoords position;
		int* number;
	};*/



	struct poscoords {
		int x;
		int y;

		poscoords(int _x, int _y) :
			x(_x),
			y(_y)
		{}

		bool operator == (poscoords rhs) const {
			return x == rhs.x && y == rhs.y;
		}
	};

	int getAllBlueprintNumbers(const string& fileName) {
		ifstream fileInput(fileName);
		int sum = 0;
		string line;
		vector<vector<string>> map;
		vector<poscoords> takenNumbersPos;
		while (getline(fileInput, line)) {
			vector<string> mapLine;
			for (char character : line) {
				if (character == '.') {
					mapLine.push_back(" ");
				}
				else {
					string charStr;
					charStr = character;
					mapLine.push_back(charStr);
				}
			}
			map.push_back(mapLine);
		}
		fileInput.close();
		regex spec("[!-\/:-@[-`{-~]");
		regex numbers(R"(\d)");
		smatch match;
		for (int x = 0; x < map.size(); x++) {
			for (int y = 0; y < map[x].size(); y++) {
				cout << "x: " << x << " y: " << y << endl;
				if (regex_match(map[x][y], match, spec)) {
					for (int xk = x == 0 ? x : x - 1; xk < x == map.size() - 1 ? x : x + 1; xk++) {
						for (int yk = y == 0 ? y : y - 1; yk < y == map[x].size() - 1 ? y : y + 1; y++) {
							if (regex_match(map[xk][yk], match, numbers) && find(takenNumbersPos.cbegin(),takenNumbersPos.cend(),poscoords(xk,yk)) == takenNumbersPos.cend()) {
								int xnum = xk - 1;
								takenNumbersPos.push_back(poscoords(xk, yk));
								int number = stoi(map[xk][yk]);
								int tenth = 1;
								while (xnum>-1 && regex_match(map[xnum][yk], match, numbers)) {
									number += stoi(map[xnum][yk])*tenth;
									takenNumbersPos.push_back(poscoords(xnum, yk));
									xnum--;
									tenth++;

								}
								xnum = xk + 1;
								while ( xnum < map[xk].size() && regex_match(map[xnum][yk], match, numbers)) {
									number = 10 * number + stoi(map[xnum][yk]);
									xnum++;
								}
								sum += number;
							}
						}
					}
				}
			}
		}
		return sum;
	}
}