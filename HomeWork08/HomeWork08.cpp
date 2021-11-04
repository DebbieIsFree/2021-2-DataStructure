#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> v(1001);
bool check[1001][1001];
bool visited[1001];

void DFS(int i, int& count);

int main() {
	int N;	cin >> N;

	while (N--) {
		int a, b;
		cin >> a >> b;
		if (!check[a][b] && !check[b][a]) {
			v[a].push_back(b);
			v[b].push_back(a);
			check[a][b] = true;
			check[b][a] = true;
		}
	}

	int hub = 0;
	int hubGroupCount = 0;
	int tmphub = 0;

	for (int i = 1; i < 1001; i++) {
		if (v[i].size() != 0) {
			if (v[hub].size() < v[i].size()) {
				hub = i;
			}
			else if (v[hub].size() == v[i].size()) {
				tmphub = i;
			}
		}
	}

	if (v[tmphub].size() < v[hub].size())
		DFS(hub, hubGroupCount);
	else {
		hub = 0;
		hubGroupCount = 0;
	}

	cout << hub << " " << hubGroupCount << "\n";


	memset(visited, 0, sizeof(visited));

	int Max = 0;
	int totalGroup = 0;

	for (int i = 1; i < 1001; i++) {
		int count = 0;
		if (v[i].size()!= 0 && !visited[i]) {
			DFS(i, count);
			totalGroup++;
		}
		if (Max < count)
			Max = count;
	}
	cout << Max << "\n" << totalGroup;
	return 0;
}



void DFS(int i, int& count) {
	count++;
	visited[i] = true;
	for(int j = 0; j < v[i].size(); j++) {
		if(!visited[v[i][j]])
			DFS(v[i][j], count);
	}
}
