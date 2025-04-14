#include "gmock/gmock.h"
#include "SimilarityCheck.cpp"

TEST(SimilarityCheck, checkCharCount1) {
	SimilarityChecker checker;
	string str1 = "AAA";
	string str2 = "BBB";

	int expected = 60;
	int actual = checker.getLengthScore(str1, str2);

	EXPECT_EQ(expected, actual);
}

TEST(SimilarityCheck, checkCharCount2) {
	SimilarityChecker checker;
	string str1 = "AAA";
	string str2 = "BB";

	int expected = 40;
	int actual = checker.getLengthScore(str1, str2);

	EXPECT_EQ(expected, actual);
}