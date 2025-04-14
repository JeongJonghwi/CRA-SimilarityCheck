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
		set<char> set1;
		set<char> set2;
		int totalCount;
		int sameCount = 0;

		for (int i = 0; i < str1.length(); i++) {
			set1.insert(str1[i]);
		}
		for (int i = 0; i < str2.length(); i++) {
			set2.insert(str2[i]);
		}

		for (char ch : set1) {
			if (set2.count(ch))
				sameCount++;
		}
		set1.insert(set2.begin(), set2.end());
		totalCount = set1.size();
		
		return ((double)sameCount / totalCount) * 40;
	}
};