#include "gmock/gmock.h"
#include "SimilarityCheck.cpp"

TEST(SimilarityCheck, checkCharCount) {
	SimilarityChecker checker;
	string str1 = "AAA";
	string str2 = "BBB";

	int expected = 60;
	int actual = checker.getCharCountScore(str1, str2);

	EXPECT_EQ(expected, actual);
}