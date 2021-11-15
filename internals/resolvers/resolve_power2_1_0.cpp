float __get_discriminant(map<float, float> tokens_map);
vector<float> __get_roots_by_Vietas(map<float, float> tokens_map);
vector<float> __get_roots_by_discriminant(map<float, float> tokens_map, float discriminant);

vector<float> resolve_power2_1_0(map<float, float> tokens_map) {
	float discriminant = __get_discriminant(tokens_map);
	if(discriminant < 0) return vector<float>();
	
	vector<float> roots = __get_roots_by_Vietas(tokens_map);
	DET print_title("Get roots by Vieta's theoreme"); 
	if(roots.size() > 0) return roots;
	
	roots = __get_roots_by_discriminant(tokens_map, discriminant);
	DET print_title("Get roots by discriminant: ");  
	return roots;
}

bool is_power2_1_0(map<float, float> tokens_map) {
	return (tokens_map.size() == 3) 
		&& map_has_key(tokens_map,  (float)2) 
		&& map_has_key(tokens_map,  (float)1) 
		&& map_has_key(tokens_map,  (float)0);
}

float __get_discriminant(map<float, float> tokens_map) {
	return pow(tokens_map[1], 2) - 4 * tokens_map[0] * tokens_map[2];
}

vector<float> __get_roots_by_Vietas(map<float, float> tokens_map) {
	float p = -tokens_map[1], q = tokens_map[0]; // x1*x2 = q; x1+x2 = p;
	DET cout << '\t' << "p=" << p << "; q=" << q << endl;
	 
	function<bool(float x)> condition = [p](float x) { return p > 0 ? (x <= 2 * p) : (x >= 2 * p); };
	function<float(float x)> step = [p](float x) { return p > 0 ? (x+1) : (x-1); };
	 
	for(float x1 = -p, x2; condition(x1); x1 = step(x1)) {
		x2 = p - x1;
		DET cout << '\t' << "Try Vieta's: " << x1 << ' ' << x2 << endl;
		if(x1 * x2 == q) {
			vector<float> roots {x1, x2};
			return roots;
		}
	}
	
	return vector<float> ();
}

vector<float> __get_roots_by_discriminant(map<float, float> tokens_map, float discriminant) {
	vector<float> roots;
	float denominator = 2 * tokens_map[2];
	
	if(discriminant == 0) roots.push_back(-tokens_map[1]/denominator); 
	else {
		roots.push_back((-tokens_map[1] + sqrt(discriminant))/denominator); 
		roots.push_back((-tokens_map[1] - sqrt(discriminant))/denominator);
	} 
	
	return roots;
}
