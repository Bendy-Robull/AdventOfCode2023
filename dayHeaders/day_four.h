#pragma once
#include "../basics.h"

namespace day_four {
	class card {
	private:
		vector<int> winningNumbers;
		vector<int> playedNumbers;
		int score;
		int amount;

	public:
		const vector<int>& getwinNums() {
			return winningNumbers;
		}
		const vector<int>& getplayed() {
			return playedNumbers;
		}
		int getScoreVal() {
			return pow(2, score-1);
		}
		
		int& getScore() {
			return score;
		}

		int& getAmount() {
			return amount;
		}

		void calcScore() {
			for (int num : playedNumbers) {
				if (find(winningNumbers.cbegin(), winningNumbers.cend(), num) != winningNumbers.cend()) {
					score++;
				}
			}
		}

		void addToWinning(int num) {
			winningNumbers.push_back(num);
		}
		void addToplayed(int num) {
			playedNumbers.push_back(num);
		}
	};


	int getPoints(const string& fileName) {
		ifstream inputFile(fileName);
		string line;
		int totalScore = 0;
		regex separator(R"(\||:)");
		regex spaceSep(R"(\s+)");
		while (getline(inputFile, line)) {
			vector<string> tokens(sregex_token_iterator{ begin(line),end(line),separator,-1 }, sregex_token_iterator{});
			vector<string> winningnumbers(sregex_token_iterator{ begin(tokens[1]),end(tokens[1]),spaceSep,-1}, sregex_token_iterator{});
			card lineCard;
			winningnumbers.erase(winningnumbers.begin());
			winningnumbers.shrink_to_fit();
			for (auto const& num : winningnumbers) {
				lineCard.addToWinning(stoi(num));
			}
			vector<string> numbers(sregex_token_iterator{ begin(tokens[2]),end(tokens[2]),spaceSep,-1 }, sregex_token_iterator{});
			numbers.erase(numbers.begin());
			numbers.shrink_to_fit();
			for (auto const& num : numbers) {
				lineCard.addToplayed(stoi(num));
			}
			lineCard.calcScore();
			totalScore += lineCard.getScoreVal();
		}
		inputFile.close();
		return totalScore;
	}

	int getAllCards(const string& fileName) {
		ifstream inputFile(fileName);
		string line;
		int totalScore = 0;
		vector<card> cards;
		map<int, int> counterMap;
		int counter = 1;
		regex separator(R"(\||:)");
		regex spaceSep(R"(\s+)");
		while (getline(inputFile, line)) {
			vector<string> tokens(sregex_token_iterator{ begin(line),end(line),separator,-1 }, sregex_token_iterator{});
			vector<string> winningnumbers(sregex_token_iterator{ begin(tokens[1]),end(tokens[1]),spaceSep,-1 }, sregex_token_iterator{});
			card lineCard;
			winningnumbers.erase(winningnumbers.begin());
			winningnumbers.shrink_to_fit();
			for (string num : winningnumbers) {
				lineCard.addToWinning(stoi(num));
			}
			vector<string> numbers(sregex_token_iterator{ begin(tokens[2]),end(tokens[2]),spaceSep,-1 }, sregex_token_iterator{});
			numbers.erase(numbers.begin());
			numbers.shrink_to_fit();
			for (auto num : numbers) {
				lineCard.addToplayed(stoi(num));
			}
			lineCard.calcScore();

			cards.push_back(lineCard);
		}
		inputFile.close();
		return totalScore;
	}
}