#include <stdexcept>
#include <string>
using namespace std;

class SimilarityChecker
{
public:
	explicit SimilarityChecker(const string answer) : answer(answer)
	{
		assertValidAnswer(answer);
	}
	float GetLengthScore(string guess);

private:
	void assertValidAnswer(const string answer);
	void assertValidInput(string guess);
	bool isMAXScore(string guess);
	bool isZeroScore(string guess);
	float calculateWithFormula(int longerLength, int shorterLength);
	float CalculateScore(string guess);

private:
	string answer;
	const int MAX_SCORE = 60;
};


float SimilarityChecker::GetLengthScore(string guess)
{
	assertValidInput(guess);

	if (isMAXScore(guess)) return MAX_SCORE;
	if (isZeroScore(guess)) return 0;

	return CalculateScore(guess);
}

void SimilarityChecker::assertValidAnswer(const string answer)
{
	if (answer.length() == 0) throw invalid_argument("Answer can't be empty string\n");
	for (auto ch : answer)
	{
		if ('A' <= ch && ch <= 'Z') continue;
		throw invalid_argument("Answer must only contain characters\n");
	}
}

void SimilarityChecker::assertValidInput(string guess)
{
	if (guess.length() == 0) throw invalid_argument("Please input a string with at least one letter\n");
	for (auto ch : guess)
	{
		if ('A' <= ch && ch <= 'Z') continue;
		throw invalid_argument("Input string must only contain characters\n");
	}
}

bool SimilarityChecker::isMAXScore(string guess)
{
	return answer.length() == guess.length();
}

bool SimilarityChecker::isZeroScore(string guess)
{
	int longerLength = max(answer.length(), guess.length());
	int shorterLength = min(answer.length(), guess.length());
	if (longerLength > shorterLength * 2) return true;
	return false;
}

float SimilarityChecker::CalculateScore(string guess)
{
	int longerLength = max(answer.length(), guess.length());
	int shorterLength = min(answer.length(), guess.length());
	return calculateWithFormula(longerLength, shorterLength);
}

float SimilarityChecker::calculateWithFormula(int longerLength, int shorterLength)
{
	return MAX_SCORE - (longerLength - shorterLength) * (MAX_SCORE / (float)shorterLength);
}
