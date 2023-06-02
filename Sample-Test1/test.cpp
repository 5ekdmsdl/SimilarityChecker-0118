#include "pch.h"
#include <string>
#include <gtest/gtest.h>
#include "../BestReview/SimilarityChecker.cpp"

TEST(SimilarityChecker, InvalidAnswer_empty)
{
	EXPECT_THROW(SimilarityChecker checker(""); , std::invalid_argument);
}

TEST(SimilarityChecker, InvalidAnswer_containsOtherthanChar)
{
	EXPECT_THROW(SimilarityChecker checker("1ABC^"); , std::invalid_argument);
}

TEST(SimilarityChecker, InvalidInput_empty)
{
	SimilarityChecker checker("ABC");
	EXPECT_THROW(checker.getLengthScore(""), std::invalid_argument);
}

TEST(SimilarityChecker, InvalidInput_containsOtherthanChar)
{
	SimilarityChecker checker("ABC");
	EXPECT_THROW(checker.getLengthScore("1ABC^"), std::invalid_argument);
}

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
