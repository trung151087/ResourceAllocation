# include <bits/stdc++.h>
# include <indi.cpp>
using namespace std;

void read_data(string file) {

	ifstream data(file);

	data >> t >> r >> s;
	for(int i = 0; i < t; i++) {
		data >> dur[i];
		maxdur = max(maxdur, dur[i]);
	}
	int n_edge, a, b;
	data >> n_edge;
	for(int i = 0; i < n_edge; i++) {
		data >> a >> b;
		a--; b--;
		adj_f[a].pb(b);
		adj_b[b].pb(a);
	}

	for(int i = 0; i < t; i++) {
		for(int j = 0; j < s; j++) {
			data>> treq[i][j];
		}
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < s; j++) {
			data >> lexp[i][j];
		}
	}
}

int main(int argc, char ** argv) {
	read_data(argv[1]);
	
}