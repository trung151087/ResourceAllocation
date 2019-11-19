# include<bits/stdc++.h>
# include "indi.cpp"

using namespace std;

# define pop_size 1000
# define tabu_size 1000

vector<Indi> get_neighbors(Indi c, int nc) {
	vector <Indi> res;
	for(int _ = 0; _ < nc; _++) {
		Indi d = mutate(c);
		d.fitn = fitness(d);
		res.pb(d);
	}

	return res;
}

void read_data(string file) {

	ifstream data(file);

	data >> t >> r >> s >> zz;
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
	Indi s0;
	vector<Indi> tabu_list;
	tabu_list.pb(s0);
	Indi candidate = s0;
	Indi best = s0;
	Indi best_neighbor;
	int best_indx;
	bool stop = false;
	int nrepeat = 0;
	int iter = 0;
	
	while(!stop) {
		iter ++;
		cout << iter << "\t";
		vector<Indi> neighbors = get_neighbors(candidate, pop_size);
		
		sort(neighbors.begin(), neighbors.end(), cmp);
	
		best_indx = 0;
		best_neighbor = neighbors[best_indx];

		while(best_indx < pop_size and is_contain(tabu_list, best_neighbor)) {
			best_indx ++;
			best_neighbor = neighbors[best_indx];
		}
		cout << best_indx << "\t";
		if (best_neighbor.fitn > best.fitn) {
			best = best_neighbor;
			nrepeat = 0;
		}

		nrepeat ++;
		if (nrepeat == 500) {
			stop = true; // SAU 500 ITER KHONG CAI THIEN DUOC KET QUA THI DUNG LAI
		}

		candidate = best_neighbor;
		tabu_list.pb(best_neighbor);
		if (tabu_list.size() > tabu_size) tabu_list.erase(tabu_list.begin());
		cout << "BEST FITNESS : " << best.fitn << "\t\t" << "BEST NEIGHBOR FITNESS : " <<best_neighbor.fitn << endl;

		if (iter%10 == 0) {
			cout << duration(best) << " " << experience(best) << " " << assignment(best) << endl;
			best.print();
		}
	}

}
