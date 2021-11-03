vector<token> move_tokens_left(vector<token> tokens) {
	int eq_index = -1;
	for(int i = 0; i < tokens.size(); i++) {
		if(tokens[i].type == EQUALS) eq_index = i; 
		if((eq_index >= 0) && (!is_tokentype_operation(tokens[i-1]))) tokens[i].value *= -1;
	} 
	tokens.erase(tokens.begin() + eq_index);
	
	return tokens; 
}
