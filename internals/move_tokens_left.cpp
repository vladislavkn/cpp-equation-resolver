vector<token> move_tokens_left(vector<token> tokens) {
	int eq_index = -1;
	
	for(int i = 0; i < tokens.size(); i++) {
		if(tokens[i].type == EQUALS) eq_index = i; 
		if(eq_index >= 0) tokens[i].value *= -1;
	}
	
	return tokens;
}
