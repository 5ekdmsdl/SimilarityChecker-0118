#include <stdexcept>
#include <string
#include <unordered_set>

using namespace std;

class SimilarityChecker
{
public:
	int getAlphaScore(const string& str1, const string& str2););
  float GetLengthScore(const string& str1, const string& str2);

private:
	void assertValidInput(const string& str1);
	int getTotalCnt(const string& str1, const string& str2);
	int getSameCnt(const string& str1, const string& str2);
	float calculateScorewithFormula(int totalCnt, int sameCnt

private:
	void CheckValidInput(string guess);
	bool isMAXScore(const string& str1, const string& str2);
	bool isZeroScore(const string& str1, const string& str2);
	float calculateWithFormula(int longerLength, int shorterLength);
	float calculateScore(const string& str1, const string& str2);

private:
	const int MAX_SCORE = 60;
};

int SimilarityChecker::getAlphaScore(const string& str1, const string& str2)
{
	assertValidInput(str1);
	assertValidInput(str2);
	
	int totalCnt = getTotalCnt(str1, str2);
	int sameCnt = getSameCnt(str1, str2);
  
	return calculateScorewithFormula(totalCnt, sameCnt);
}
                                  
float SimilarityChecker::GetLengthScore(const string& str1, const string& str2)
{
	CheckValidInput(str1);
	CheckValidInput(str2);

	if (isMAXScore(str1, str2)) return MAX_SCORE;
	if (isZeroScore(str1, str2)) return 0;

	return calculateScore(str1, str2);
}
                                  

void SimilarityChecker::assertValidInput(const string& str1)
{
	for(auto ch : str1)
	{
		if('A' <= ch && ch <= 'Z') continue;
		throw invalid_argument("Input string must be consist of CAPITAL LETTERS!!");
	}
}

int SimilarityChecker::getTotalCnt(const string& str1, const string& str2)
{
	unordered_set<char> pool1;
	for(auto ch : str1)
	{
		pool1.insert(ch);

	}
	unordered_set<char> pool2;
	for(auto ch : str2)
	{
		pool2.insert(ch);
	}
	return max(pool1.size(),pool2.size());
}

int SimilarityChecker::getSameCnt(const string& str1, const string& str2)
{
	unordered_set<char> pool1;
	for (auto ch : str1)
	{
		pool1.insert(ch);

	}
	int cnt = 0;
	for(auto ch : str2)
	{
		if(pool1.find(ch) != pool1.end())
		{
			cnt++;
			pool1.erase(ch);
		}
	}
	return cnt;
}

float SimilarityChecker::calculateScorewithFormula(int totalCnt, int sameCnt)
{
	return (sameCnt / (float)totalCnt) * 40;
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
