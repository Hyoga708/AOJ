#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<int> date[30];
		vector<set<int>> dat(n);
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			for (int j = 0; j < m; j++) {
				int f;
				cin >> f;
				f--;
				date[f].push_back(i);
			}
		}
		for (int i = 0; i < n; i++)
			dat[i].insert(i);
		int ret = 0;
		while (ret < 30) {
			for (int i = 0; i < date[ret].size(); i++) {
				int from = date[ret][i];
				for (int j = 0; j < date[ret].size(); j++) {
					int to = date[ret][j];
					for (int it : dat[from])
						dat[to].insert(it);
				}
			}
			bool end = false;
			for (int i = 0; i < n; i++) {
				if (dat[i].size() == n) {
					end = true;
					break;
				}
			}
			if (end)
				break;
			ret++;
		}
		cout << (ret == 30 ? -1 : ret + 1) << endl;
	}
	return 0;
}
