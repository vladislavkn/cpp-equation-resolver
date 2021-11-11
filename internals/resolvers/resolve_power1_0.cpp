vector<float> resolve_power1_0(map<float, float> tokens_map) {
	vector<float> results = { -tokens_map[0]/tokens_map[1] };
	return results;
}

bool is_power1_0(map<float, float> tokens_map) {
	return (tokens_map.size() == 2) && map_has_key(tokens_map,  (float)0) && map_has_key(tokens_map, (float)1);
}
