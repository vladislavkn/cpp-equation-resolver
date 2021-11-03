
vector<token> apply_multiplications(vector<token> tokens) {
	for(int i = 1; i < tokens.size(); i++) {
		if(tokens[i].type != MULTIPLY) continue;
		
		if(tokens[i-1].type == VARIABLE) {  
			if(tokens[i+1].type == VARIABLE) {  
				tokens[i-1].value *= tokens[i+1].value;
				tokens[i-1].power += tokens[i+1].power;
			} else if(tokens[i+1].type == NUMBER) {
				tokens[i-1].value *= tokens[i+1].value;
			}
			tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
		} else if(tokens[i-1].type == NUMBER) {
			tokens[i+1].value *= tokens[i-1].value;
			tokens.erase(tokens.begin() + i - 1, tokens.begin() + i + 1);
		}
		
		i -= 2;
	}
	
	return tokens;
}
