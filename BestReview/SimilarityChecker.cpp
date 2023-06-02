#include <stdexcept>
#include <string>
using namespace std;

class SimilarityChecker
{
public:
	float GetLengthScore(const string& str1, const string& str2);

private:
	void CheckValidInput(string guess);
	bool isMAXScore(const string& str1, const string& str2);
	bool isZeroScore(const string& str1, const string& str2);
	float calculateWithFormula(int longerLength, int shorterLength);
	float calculateScore(const string& str1, const string& str2);

private:
	const int MAX_SCORE = 60;
};


float SimilarityChecker::GetLengthScore(const string& str1, const string& str2)
{
	CheckValidInput(str1);
	CheckValidInput(str2);

	if (isMAXScore(str1, str2)) return MAX_SCORE;
	if (isZeroScore(str1, str2)) return 0;

	return calculateScore(str1, str2);
}

void SimilarityChecker::CheckValidInput(string guess)
{
	if (guess.length() == 0) throw invalid_argument("Please input a string with at least one letter\n");
	for (auto ch : guess)
	{
		if ('A' <= ch && ch <= 'Z') continue;
		throw invalid_argument("Input string must only contain characters\n");
	}
}

bool SimilarityChecker::isMAXScore(const string& str1, const string& str2)
{
	return str1.length() == str2.length();
}

bool SimilarityChecker::isZeroScore(const string& str1, const string& str2)
{
	int longerLength = max(str2.length(), str1.length());
	int shorterLength = min(str2.length(), str1.length());
	if (longerLength >= shorterLength * 2) return true;
	return false;
}

float SimilarityChecker::calculateScore(const string& str1, const string& str2)
{
	int longerLength = max(str2.length(), str1.length());
	int shorterLength = min(str2.length(), str1.length());
	return calculateWithFormula(longerLength, shorterLength);
}

float SimilarityChecker::calculateWithFormula(int longerLength, int shorterLength)
{
	return MAX_SCORE - (longerLength - shorterLength) * (MAX_SCORE / (float)shorterLength);
}
