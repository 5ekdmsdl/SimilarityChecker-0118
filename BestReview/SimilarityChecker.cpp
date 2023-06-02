#include <string>
using namespace std;

class SimilarityChecker
{
public:
	explicit SimilarityChecker(const string answer) : answer(answer) {};
	int getScore1(string guess);

	string answer;
};

int SimilarityChecker::getScore1(string guess)
{
	if (answer.length() == guess.length()) return 60;
	return 0;
}

