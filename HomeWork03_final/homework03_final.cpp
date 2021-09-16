#include <iostream>
#include <bitset>
using namespace std;

bool bmap[64][64];
bool tmap[64][64];

int main() {

	for (int i = 0; i < 64; i++) {
		long long num;
		cin >> num;

		bitset<64> bit(num);

		string s = bit.to_string();

		for (string::size_type j = 0; j < s.size(); j++) {
			bmap[i][64 - s.size() + j] = s[j] - '0';
		}
	}

	for (int i = 0; i < 64; i++) {
		long long total = 0;
		long pow = 1;
		for (int j = 0; j < 64; j++) {
			tmap[i][j] = bmap[j][i];
		}
	}

	for (int i = 0; i < 64; i++) {
		string str = "";
		for (int j = 0; j < 64; j++) {
			str += tmap[i][j] + '0';
		}

		bitset<64> bit2(str);

		long long tmp = bit2.to_ullong();
		cout << tmp << "\n";
	}

	return 0;
}