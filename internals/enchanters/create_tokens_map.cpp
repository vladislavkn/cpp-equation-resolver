map<float, float> create_tokens_map(vector<token> tokens) {
	map<float, float> tokens_map;
	
	for(int i = 0; i < tokens.size(); i++) 
		if(tokens_map.find(tokens[i].power) == tokens_map.end()) 
			tokens_map[tokens[i].power] = tokens[i].value;
		else
			tokens_map[tokens[i].power] += tokens[i].value;
	
	return tokens_map;
}

void print_tokens_map(map<float, float> tokens_map, string prefix="") {
	for(auto p: tokens_map)	cout << prefix << p.first << ": " << p.second << endl;
}
