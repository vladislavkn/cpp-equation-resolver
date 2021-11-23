float __get_discriminant(map<float, float> tokens_map);
vector<float> __get_roots_by_Vietas(map<float, float> tokens_map);
vector<float> __get_roots_by_discriminant(map<float, float> tokens_map, float discriminant);
float const ACCURACY = (float) 1 / pow(10, 8);

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
	float p = -tokens_map[1]/tokens_map[2], q = tokens_map[0]/tokens_map[2]; // x1*x2 = q; x1+x2 = p;
	float last_diff = 0, diff = 0, fault_range = 0;
	int stage_level = 0, direction = 1;
	DET cout << '\t' << "p=" << p << "; q=" << q << endl;
	 
	// Step value or fault range for current step
	auto get_fault_range = [](float stage_level) {
		return (float) 1 / pow(10, stage_level);  
	};
	auto condition = [p](float x, int direction) {
		return (p * direction) > 0 ? (x <= 2 * p + 1) : (x >= 2 * p - 1); 
	};
	auto get_step = [p](float addition, int direction) { 
		return (p * direction) > 0 ? addition : -addition;
	}; 
	
	 
	for(float x1 = -p, x2; condition(x1, direction); x1 += get_step(get_fault_range(stage_level), direction)) {
		x2 = p - x1;
		// Get fault range for current step
		fault_range = get_fault_range(stage_level);
		DET cout << '\t' << "Try Vieta's: stage:" << ((float) 1 / pow(10, stage_level)) << " x1:" << x1 << " x2:" << x2 << " qx:" << (x1 * x2) << " diff:" << abs(x1 * x2 - q) << " last:" << last_diff << " pass:" << (abs(x1 * x2 - q) < ACCURACY) << endl;
		
		// Get diff
		diff = abs(x1 * x2 - q);
		
		// If diff is growing, we change the direction
		if((diff > last_diff) && (last_diff != 0)) {
			DET print_title("Set direction to " + to_string(-direction) + " and stage_level to " + to_string(stage_level));
			direction = -direction;
			stage_level += 1;
			last_diff = 0; // Set last_diff to 0 to prevent direction changing
		// If we reached enough accuracy for that step, update step value
		} else if((diff < fault_range) && (diff < abs(q))) { 
			// If we've reached max level of cpp accuracy, return result 
			if((stage_level > 8) || (abs(x1 * x2 - q) < ACCURACY)) {
				vector<float> roots {x1, x2};
				return roots;
			}
			
			// Else fallback for 1 step
			x1 -= get_step(fault_range, direction); 
			// Update step value modifier 
			stage_level += 1; 
			DET print_title("Set stage_level to " + to_string(stage_level)); 
			last_diff = 0; // Set last_diff to 0 to prevent direction changing
		} else {
			last_diff = diff; // Update last diff to detect whether we should to change the direction
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
