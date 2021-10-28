using namespace std;

vector<token> analyze(vector<token> tokens) {
	map<float, float> value;
	
	if(ENABLE_LOGGING) {
		start_group("START ANALYZING");
		for(token t: tokens) t.print_repr();
		end_group();
	}
	
	if(ENABLE_LOGGING) start_group("START POWERS"); 
	
	// eval powers
	for(int i = 0; i < tokens.size(); i++)
		if(tokens[i].type == POWER) {
			if(tokens[i-1].type == NUMBER) {
				tokens[i-1].value = pow(tokens[i-1].value, tokens[i+1].value);
			} else if(tokens[i-1].type == VARIABLE) {
				if(tokens[i-1].power == 1) tokens[i-1].power -= 1;
				tokens[i-1].power += tokens[i+1].value;
			}
			
			tokens.erase(tokens.begin() + i);
			tokens.erase(tokens.begin() + i); 
			
			if(ENABLE_LOGGING) {
				start_group("POWERS");
				cout << "Found at i=" << i << endl;
				for(token t: tokens) t.print_repr();
				end_group();
			}
			i -= 1;
		}
		
	if(ENABLE_LOGGING) start_group("START MULTIPLYING"); 
	
	// eval multiplies	
	for(int i = 0; i < tokens.size(); i++)
		if(tokens[i].type == MULTIPLY) {
			if(tokens[i-1].type == NUMBER) {
				if(tokens[i+1].type == NUMBER) {
					tokens[i-1].value = tokens[i-1].value * tokens[i+1].value;
					tokens.erase(tokens.begin() + i);
					tokens.erase(tokens.begin() + i);
				} else if(tokens[i+1].type == VARIABLE) {
					tokens[i+1].value = tokens[i-1].value;
					tokens.erase(tokens.begin() + i);
					tokens.erase(tokens.begin() + i - 1);
				}
			} else if(tokens[i-1].type == VARIABLE) {
				if(tokens[i+1].type == NUMBER) {
					tokens[i-1].value *= tokens[i+1].value;
					tokens.erase(tokens.begin() + i);
					tokens.erase(tokens.begin() + i);
				} else if(tokens[i+1].type == VARIABLE) {
					tokens[i-1].value *= tokens[i+1].value;
					tokens[i-1].power += tokens[i+1].power;
					tokens.erase(tokens.begin() + i);
					tokens.erase(tokens.begin() + i);
				}
			}	
			if(ENABLE_LOGGING) {
				start_group("MULTIPLYING");
				cout << "Found at i=" << i << endl;
				for(token t: tokens) t.print_repr();
				end_group();
			}
			i -= 1;
		}	
	
	if(ENABLE_LOGGING) {
		start_group("FINISH ANALYZING");
		for(token t: tokens) t.print_repr();
		end_group();
	}
	
	return tokens;
}

template <typename K, typename V>
V get_hashmap_value(map<K, V> hashmap, K key) {
	if(hashmap.find(key) != hashmap.end()) return hashmap[key];
	return (V) 0;
}

map<float, float> build_hashmap(vector<token> tokens) {
	map <float, float> repr;
	repr[0] = 0;
	float sign = 1;
	
	if((tokens[0].type != ADD) && (tokens[0].type != SUBSTITUTE)) {
		tokens.insert(tokens.begin() + 0, token::make(ADD));
	}
	
	if(ENABLE_LOGGING) start_group("START HASHMAP"); 
	
	for(int i = 0; i < tokens.size(); i+=1) {
		sign = tokens[i].type == ADD ? 1 : -1; 
		
		if(tokens[i+1].type == VARIABLE) {
			repr[tokens[i+1].power] = get_hashmap_value<float, float>(repr, tokens[i+1].power) + abs(tokens[i+1].value) * sign;
		} else if(tokens[i+1].type == NUMBER) {
			repr[0] = get_hashmap_value<float, float>(repr, 0) + abs(tokens[i+1].value) * sign;
		} else continue;
		
		if(ENABLE_LOGGING) {
			start_group("EVALUATED TOKEN");
			cout << "Index = " << i << endl;
			tokens[i].print_repr();
			tokens[i+1].print_repr();
			end_group();
		};
	}
	
	if(ENABLE_LOGGING) start_group("START ERASING"); 
	
	for(auto it = repr.cbegin(); it != repr.end(); it++) {
		if(it->first == 0) continue;
		if(it->second == 0) {
			if(ENABLE_LOGGING) {
				start_group("ERASE");
				cout << it->first << " " << it->second << endl;
				end_group(); 
			}
			repr.erase(it->first);
			it--;
		}
	}
	
	if(ENABLE_LOGGING) {
		start_group("FINISH HASHMAP");
		for(pair<float, float> p: repr) cout << p.first << ": " << p.second << endl; 
		end_group();
	}
	
	return repr;		
}
