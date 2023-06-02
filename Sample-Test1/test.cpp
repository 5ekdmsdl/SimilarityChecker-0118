#include "pch.h"
#include <string>
#include <gtest/gtest.h>
#include "../BestReview/SimilarityChecker.cpp"

TEST(SimilarityChecker, LengthDoubleLonger)
{
	SimilarityChecker checker("A");
	EXPECT_EQ(0, checker.getScore1("BB"));
}

TEST(SimilarityChecker, PerfectMatch)
{
	SimilarityChecker checker("ASD");
	EXPECT_EQ(60, checker.getScore1("DSA"));
}

/*
TEST(SimilarityChecker, PartialScore1)
{
	SimilarityChecker checker("AAABB");
	EXPECT_EQ(60, checker.getScore1("BAA"));
}*/
