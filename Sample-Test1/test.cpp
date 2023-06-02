#include "pch.h"
#include <string>
#include <gtest/gtest.h>
#include "../BestReview/SimilarityChecker.cpp"

TEST(SimilarityChecker, InvalidInput_SmallLetter)
{
	SimilarityChecker check;
	EXPECT_THROW(check.getAlphaScore("abc", "BC") , invalid_argument);
	EXPECT_THROW(check.getAlphaScore("BC", "abc") , invalid_argument);
}

TEST(SimilarityChecker, InvalidInput_empty)
{
	SimilarityChecker checker;
	EXPECT_THROW(checker.GetLengthScore("","ABC"), std::invalid_argument);
	EXPECT_THROW(checker.GetLengthScore("ABC",""), std::invalid_argument);
}

TEST(SimilarityChecker, InvalidInput_containsOtherthanChar)
{
	SimilarityChecker checker;
	EXPECT_THROW(checker.GetLengthScore("1ABC&","ABC"), std::invalid_argument);
	EXPECT_THROW(checker.GetLengthScore("ABC","1ABC^"), std::invalid_argument);
}

TEST(SimilarityChecker, LengthDoubleLonger)
{
	SimilarityChecker checker;
	EXPECT_EQ(0, checker.GetLengthScore("A", "BB"));
}

TEST(SimilarityChecker, PerfectMatch)
{
	SimilarityChecker checker;
	EXPECT_EQ(60, checker.GetLengthScore("ASD", "DSA"));
}

TEST(SimilarityChecker, PartialScore1)
{
	SimilarityChecker checker;
	EXPECT_EQ(20.0, checker.GetLengthScore("AAABB", "BAA"));
}

TEST(SimilarityChecker, PartialScore2)
{
	SimilarityChecker checker;
	EXPECT_EQ(30.0, checker.GetLengthScore("AA", "AAA"));
}

TEST(SimilarityChecker, AllDiff)
{
	SimilarityChecker check;
	EXPECT_EQ(check.getAlphaScore("ABC", "EFG") , 0);
}

TEST(SimilarityChecker, MAX_SCORE)
{
	SimilarityChecker check;
	EXPECT_EQ(check.getAlphaScore("AAABB", "AB"), 40);
}

TEST(SimilarityChecker, partial_SCORE)
{
	SimilarityChecker check;
	EXPECT_EQ(check.getAlphaScore("AA", "AAE") , 20);
}