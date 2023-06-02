#include "pch.h"
#include <string>
#include <gtest/gtest.h>
#include "../BestReview/SimilarityChecker.cpp"

TEST(SimilarityChecker, LengthDoubleLonger)
{
	SimilarityChecker checker("A");
	EXPECT_EQ(0, checker.getLengthScore("BB"));
}

TEST(SimilarityChecker, PerfectMatch)
{
	SimilarityChecker checker("ASD");
	EXPECT_EQ(60, checker.getLengthScore("DSA"));
}

TEST(SimilarityChecker, PartialScore1)
{
	SimilarityChecker checker("AAABB");
	EXPECT_EQ(20.0, checker.getLengthScore("BAA"));
}

TEST(SimilarityChecker, PartialScore2)
{
	SimilarityChecker checker("AA");
	EXPECT_EQ(30.0, checker.getLengthScore("AAA"));
}
