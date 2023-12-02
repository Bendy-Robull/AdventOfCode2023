#pragma once
#include "../basics.h"

namespace day_two {
	int sumOfGameIDS(const string& fileName) {
		//piros 12, zöld 13, kék 14
		ifstream fileStream(fileName);
		string line;
		int counter = 1;
		int sum = 0;
		map<string,int> ballCounter({ {"blue",0},{"red",0},{"green",0} });
		while (getline(fileStream, line)) {
			regex splitter(R"(:|;)");
			vector<string> tokens(sregex_token_iterator{ begin(line),end(line),splitter,-1 }, sregex_token_iterator{});
			tokens.erase(tokens.begin());
			regex commaSplit(R"(,)");
			for (string balls : tokens) {
				vector<string> colorstr(sregex_token_iterator{ begin(balls),end(balls),commaSplit,-1}, sregex_token_iterator{});
				for (string ball : colorstr) {
					stringstream ss(ball);
					string color;
					int number;
					ss >> number >> color;
					ballCounter[color]=ballCounter[color]>number?ballCounter[color]:number;
				}
			}
			if (ballCounter["red"] <= 12 && ballCounter["green"] <= 13 && ballCounter["blue"] <= 14) {
				sum += counter;
			}
			counter++;
			ballCounter["red"] = 0;
			ballCounter["blue"] = 0;
			ballCounter["green"] = 0;
		}
		return sum;
	}
}