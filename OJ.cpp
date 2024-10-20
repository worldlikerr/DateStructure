#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
vector<string> v;
map<string, int> m;
string resort(const string& s) {
	string ans = s;
	for (int i = 0; i < ans.length(); i++) {
		ans[i] = tolower(ans[i]);
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main() {
	string s;
	while (cin >> s) {
		if (s[0] == '#')return;
		v.push_back(s);
		string ss=resort(s);
		if (!m.count(ss))m[ss] = 0;
		m[ss]++;
	}
	vector<string> ans;
	for (int i = 0; i < v.size(); i++) {
		if (m[resort(v[i])] == 1)ans.push_back(v[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

}