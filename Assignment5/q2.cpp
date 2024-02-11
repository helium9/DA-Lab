#include <bits/stdc++.h>
using namespace std;

struct QueueEntry {
	int vertex;
	int distance;
};

int getMinDiceThrows(int moves[], int N) {
	bool* visited = new bool[N]();
	queue<QueueEntry> q;
	visited[0] = true;
	QueueEntry start = { 0, 0 };
	q.push(start);

	QueueEntry current;
	while (!q.empty()) {
		current = q.front();
		int v = current.vertex;
		if (v == N - 1)
			break;
		q.pop();
		for (int j = v + 1; j <= (v + 6) && j < N; ++j) {
			if (!visited[j]) {
				QueueEntry next;
				next.distance = (current.distance + 1);
				visited[j] = true;
				next.vertex = (moves[j] != -1) ? moves[j] : j;
				q.push(next);
			}
		}
	}
	return current.distance;
}

int main() {
	int boardSize = 30;
	int moves[boardSize] = { -1 };

    // Ladders
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

    // Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;
	cout << "Minimum number of dice throws required is " << getMinDiceThrows(moves, boardSize);
	return 0;
}

// time complexity: O(N)
// space complexity: O(N)