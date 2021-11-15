vector<float> resolve(map<float, float> tokens_map) {
	if(is_power1_0(tokens_map)) {
		DET print_title("Resolve by power1_0");
		return resolve_power1_0(tokens_map);
	}
	if(is_power2_0(tokens_map)) {
		DET print_title("Resolve by power2_0");
		return resolve_power2_0(tokens_map);
	}
	if(is_power2_1(tokens_map)) {
		DET print_title("Resolve by power2_1");
		return resolve_power2_1(tokens_map);
	}
	if(is_power2_1_0(tokens_map)) {
		DET print_title("Resolve by power2_1_0");
		return resolve_power2_1_0(tokens_map);
	}
	
	return vector<float>(0);
}


void print_results(vector<float> results, string prefix="") {
	cout << prefix;
	for(float value: results) cout << value << ' ';
	cout << endl;
}
