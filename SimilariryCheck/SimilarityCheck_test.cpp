#include "gmock/gmock.h"
#include "SimilarityCheck.cpp"

class SimilarityCheckFixture : public testing::Test {
public:
	SimilarityChecker checker;

	void checkLengthScore(int expected, string str1, string str2) {
		int actual = checker.getLengthScore(str1, str2);
		EXPECT_EQ(expected, actual);
	}

	void checkCharScore(int expected, string str1, string str2) {
		int actual = checker.getCharScore(str1, str2);
		EXPECT_EQ(expected, actual);
	}

	void checkStringScore(int expected, string str1, string str2) {
		int actual = checker.getScore(str1, str2);
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

TEST_F(SimilarityCheckFixture, checkSameChar1) {
	string str1 = "ASD";
	string str2 = "DSA";
	int expected = 40;

	checkCharScore(expected, str1, str2);
}

TEST_F(SimilarityCheckFixture, checkSameChar2) {
	string str1 = "A";
	string str2 = "BB";
	int expected = 0;

	checkCharScore(expected, str1, str2);
}

TEST_F(SimilarityCheckFixture, checkSameChar3) {
	string str1 = "AAABB";
	string str2 = "BA";
	int expected = 40;

	checkCharScore(expected, str1, str2);
}

TEST_F(SimilarityCheckFixture, checkSameChar4) {
	string str1 = "AA";
	string str2 = "AAE";
	int expected = 20;

	checkCharScore(expected, str1, str2);
}

TEST_F(SimilarityCheckFixture, checkScore) {
	string str1 = "ASD";
	string str2 = "DSA";
	int expected = 100;

	checkStringScore(expected, str1, str2);
}