#include <string>
#include <set>

using std::string;
using std::set;

class SimilarityChecker {
public:
	int getLengthScore(string str1, string str2) {
		int len1 = (int)str1.length();
		int len2 = (int)str2.length();
		if (len1 > len2) std::swap(len1, len2);

		return (1 - ((double)(len2 - len1) / len2)) * 60;
	}

	int getCharScore(string str1, string str2) {
		set<char> chars1;
		set<char> chars2;
		int totalCount;
		int sameCount = 0;

		chars1.insert(str1.begin(), str1.end());
		chars2.insert(str2.begin(), str2.end());

		for (char ch : chars2) {
			if (chars1.count(ch))
				sameCount++;
		}

		chars1.insert(chars2.begin(), chars2.end());
		totalCount = chars1.size();
		
		return ((double)sameCount / totalCount) * 40;
	}
};