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

TEST(SimilarityTest, checkSameChar1) {
	SimilarityChecker checker;
	string str1 = "ASD";
	string str2 = "DSA";

	int expected = 40;
	int actual = checker.getCharScore(str1, str2);

	EXPECT_EQ(expected, actual);
}

TEST(SimilarityTest, checkSameChar2) {
	SimilarityChecker checker;
	string str1 = "A";
	string str2 = "BB";

	int expected = 0;
	int actual = checker.getCharScore(str1, str2);

	EXPECT_EQ(expected, actual);
}

TEST(SimilarityTest, checkSameChar3) {
	SimilarityChecker checker;
	string str1 = "AAABB";
	string str2 = "BA";

	int expected = 40;
	int actual = checker.getCharScore(str1, str2);

	EXPECT_EQ(expected, actual);
}

TEST(SimilarityTest, checkSameChar4) {
	SimilarityChecker checker;
	string str1 = "AA";
	string str2 = "AAE";

	int expected = 20;
	int actual = checker.getCharScore(str1, str2);

	EXPECT_EQ(expected, actual);
}