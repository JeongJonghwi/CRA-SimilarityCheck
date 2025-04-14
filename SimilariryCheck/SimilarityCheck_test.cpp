#include "gmock/gmock.h"
#include "SimilarityCheck.cpp"

class SimilarityCheckFixture : public testing::Test {
public:
	SimilarityChecker checker;

	void checkLengthScore(int expected, string str1, string str2) {
		int actual = checker.getLengthScore(str1, str2);
		EXPECT_EQ(expected, actual);
	}
};

TEST_F(SimilarityCheckFixture, checkCharCount1) {
	string str1 = "AAA";
	string str2 = "BBB";
	int expected = 60;

	checkLengthScore(expected, str1, str2);
}

TEST_F(SimilarityCheckFixture, checkCharCount2) {
	string str1 = "AAA";
	string str2 = "BB";
	int expected = 40;

	checkLengthScore(expected, str1, str2);
}