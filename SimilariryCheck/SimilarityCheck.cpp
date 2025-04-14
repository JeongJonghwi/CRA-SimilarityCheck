#include <string>

using std::string;

class SimilarityChecker {
public:
	int getLengthScore(string str1, string str2) {
		int len1 = (int)str1.length();
		int len2 = (int)str2.length();
		if (len1 > len2) std::swap(len1, len2);

		return (1 - ((double)(len2 - len1) / len2)) * 60;
	}
};