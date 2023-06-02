#include <string>
using namespace std;

class SimilarityChecker
{
public:
	explicit SimilarityChecker(const string answer) : answer(answer) {};
	float getScore1(string guess);

private:
	bool IsMAXScore(string guess);
	bool IsZeroScore(string guess);
	float calculateWithFormula(int longerLength, int shorterLength);
	float CalculateScore(string guess);

private:
	string answer;
	const int MAX_SCORE = 60;
};

float SimilarityChecker::getScore1(string guess)
{
	if (IsMAXScore(guess)) return MAX_SCORE;
	if (IsZeroScore(guess)) return 0;

	return CalculateScore(guess);
}

bool SimilarityChecker::IsMAXScore(string guess)
{
	return answer.length() == guess.length();
}

bool SimilarityChecker::IsZeroScore(string guess)
{
	int longerLength = (answer.length() > guess.length()) ? answer.length() : guess.length();
	int shorterLength = (answer.length() > guess.length()) ? guess.length() : answer.length();
	if (longerLength > shorterLength * 2) return true;
	return false;
}

float SimilarityChecker::CalculateScore(string guess)
{
	int longerLength = (answer.length() > guess.length()) ? answer.length() : guess.length();
	int shorterLength = (answer.length() > guess.length()) ? guess.length() : answer.length();
	return calculateWithFormula(longerLength, shorterLength);
}

float SimilarityChecker::calculateWithFormula(int longerLength, int shorterLength)
{
	return MAX_SCORE - (longerLength - shorterLength) * (MAX_SCORE / (float)shorterLength);
}
