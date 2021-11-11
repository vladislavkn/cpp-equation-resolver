vector<float> resolve(map<float, float> tokens_map) {
	if(is_power1_0(tokens_map)) return resolve_power1_0(tokens_map);
	if(is_power2_0(tokens_map)) return resolve_power2_0(tokens_map);
	
	return vector<float>();
}
