#include <stdexcept>
#include <string>
#include <unordered_set>
using namespace std;

class SimilarityChecker
{
public:
	int getAlphaScore(const string& str1, const string& str2);

private:
	void assertValidInput(const string& str1);
	int getTotalCnt(const string& str1, const string& str2);
	int getSameCnt(const string& str1, const string& str2);
	float calculateScorewithFormula(int totalCnt, int sameCnt);
};

int SimilarityChecker::getAlphaScore(const string& str1, const string& str2)
{
	assertValidInput(str1);
	assertValidInput(str2);

	
	int totalCnt = getTotalCnt(str1, str2);

	int sameCnt = getSameCnt(str1, str2);
	return calculateScorewithFormula(totalCnt, sameCnt);
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
