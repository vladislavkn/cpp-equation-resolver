vector<token> apply_powers(vector<token> tokens) {
	for(int i = 1; i < tokens.size(); i++) {
		if(tokens[i].type != POWER) continue;
		
		if(tokens[i-1].type == VARIABLE) {  
			tokens[i-1].power *= tokens[i+1].value;
		} else if(tokens[i-1].type == NUMBER) {
			tokens[i-1].value = pow(tokens[i-1].value, tokens[i+1].value);
		}
		tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
		i -= 2;
	}
	
	return tokens;
}
