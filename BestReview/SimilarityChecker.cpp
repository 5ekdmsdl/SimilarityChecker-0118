#include <string>
using namespace std;

class SimilarityChecker
{
public:
	explicit SimilarityChecker(const string answer) : answer(answer) {};
	float getScore1(string guess);

	string answer;
};

float SimilarityChecker::getScore1(string guess)
{
	if (answer.length() == guess.length()) return 60;

	int longLength = 0;
	int shortLength = 0;
	if(answer.length() > guess.length())
	{
		longLength = answer.length();
		shortLength = guess.length();
	}
	else
	{
		longLength = guess.length();
		shortLength = answer.length();
	}
	if (longLength > shortLength * 2) return 0;

	float score = (60 - (longLength - shortLength) * (60 / (float) shortLength)) ;
	return score;

	return 0;
}

