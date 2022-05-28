#include <iostream>
#include <queue>
using namespace std;


int w, k, n;
queue <int> q;
queue <int> temp;

int main() {
	cin >> w >> k >> n;

	for (int i = 0; i < n; i++) {
		int tmp;	cin >> tmp;
		q.push(tmp);
	}


	int total = 0;


	while (!q.empty()) {
		total++;
		int people = 0;
		int weight = 0;

		while (people < k) {
			if (q.empty() || (weight + q.front() > w))
				break;

			if (!q.empty()) {
				weight += q.front();
				temp.push(q.front());
				q.pop();
				people++;
			}
			else break;
		}

		if (people < k) {
			while (!temp.empty()) {
				temp.pop();
			}
			continue;
		}


		while (1) {
			if (!temp.empty()) {
				weight -= temp.front();
				temp.pop();
				people--;
			}
			else break;
			if (!q.empty()) {
				if (weight + q.front() <= w) {
					weight += q.front();
					temp.push(q.front());
					q.pop();
					people++;
				}
				else {
					while (!temp.empty()) {
						temp.pop();
					}
				}
			}
		}
	}

	cout << total;

	return 0;
}
