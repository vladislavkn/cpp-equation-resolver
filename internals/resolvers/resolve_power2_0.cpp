vector<float> resolve_power2_0(map<float, float> tokens_map) {
	float predicat = -tokens_map[0]/tokens_map[2];
	if(predicat) return vector<float>(); 
	vector<float> results { sqrt(predicat), -sqrt(predicat) };
	
	return results;
}

bool is_power2_0(map<float, float> tokens_map) {
	return (tokens_map.size() == 2) && map_has_key(tokens_map,  (float)0) && map_has_key(tokens_map, (float)2);
}
