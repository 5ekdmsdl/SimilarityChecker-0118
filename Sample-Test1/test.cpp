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