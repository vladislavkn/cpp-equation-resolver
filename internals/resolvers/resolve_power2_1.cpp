vector<float> resolve_power2_1(map<float, float> tokens_map) {
	vector<float> results = { -tokens_map[1]/tokens_map[2], 0 };
	return results;
}

bool is_power2_1(map<float, float> tokens_map) {
	return (tokens_map.size() == 2) && map_has_key(tokens_map,  (float)1) && map_has_key(tokens_map, (float)2);
}
