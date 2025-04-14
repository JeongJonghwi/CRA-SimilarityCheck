#include "gmock/gmock.h"
#include "SimilarityCheck.cpp"

class SimilarityCheckFixture : public testing::Test {
public:
	SimilarityChecker checker;

	void checkStringScore(int expected, string str1, string str2) {
		int actual = checker.getScore(str1, str2);
		EXPECT_EQ(expected, actual);
	}
};

TEST_F(SimilarityCheckFixture, checkScore) {
	string str1 = "ASD";
	string str2 = "DSA";
	int expected = 100;

	checkStringScore(expected, str1, str2);
}