#include <iostream>

using namespace std;

int arr[1500][1500];


int main() {
	int N;	cin >> N;
	if (N == -1)
		return 0;


	while (N--) {
		int x, y, w, h;
		cin >> x >> y >> w >> h;

		int hh = h / 2;
		int ww = w / 2;

		for (int i = y - hh; i < y + hh; i++) {
			for (int j = x - ww; j < x + ww; j++) {
				if (arr[i][j] == 0) arr[i][j] = 1;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < 1500; i++) {
		for (int j = 0; j < 1500; j++) {
			if (arr[i][j] == 1)
				result++;
		}
	}


	cout << result;

	return 0;
}
