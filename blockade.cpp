#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> s;

vector<int> v[100];
int visited[100];
bool articulationP[100];

int num;

vector<pair<int, int>> findmax;
void find(int idx);
bool com(pair<int, int>& p1, pair<int, int>& p2);


int DFS(int cur, bool root)
{
    visited[cur] = ++num;
    int result = visited[cur];

    int count = 0;

    for (int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];

        if (visited[next])
        {
            result = min(result, visited[next]);
            continue;
        }

        count++;
        int before = DFS(next, false);

        if (!root && before >= visited[cur])
            articulationP[cur] = true;

        result = min(result, before);
    }

    if (root)
        articulationP[cur] = (count >= 2);

    return result;
}
int main()
{
    int V;  cin >> V;
    int i = 0;
    while (1) {
        string c;   cin >> c;
        if (c == "-1")break;
        s.push_back(c);
        for (int j = 0; j < V; j++) {
            int d;  cin >> d;
            v[i].push_back(d);
        }
        i++;
    }

    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFS(i, true);


    int cnt = 0;
    for (int i = 0; i < V; i++)
        if (articulationP[i])
            cnt++;


    if (cnt == 0) {
        cout << "None";
        return 0;
    }


    for (int i = 0; i < V; i++) {
        if (articulationP[i]) {
            find(i);
        }
    }

    sort(findmax.begin(), findmax.end(), com);


    int index = findmax[0].second;
    cout << s[index];

    return 0;
}


void find(int idx) {
    int sum = 0;
    for (int i = 0; i < v[idx].size(); i++) {
        sum += v[idx][i];
    }
    findmax.push_back({ sum, idx });
}


bool com(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first > p2.first;
}
