vector<token> apply_signs(vector<token> tokens) {
	int multiplyer; 
	
	for(int i = 1; i < tokens.size(); i++) {
		if((tokens[i].type != NUMBER) || !is_tokentype_sign(tokens[i-1]))	continue;
		
		multiplyer = tokens[i-1].type == SUBSTITUTE ? -1 : 1;
		tokens[i].value *= multiplyer; 
		tokens.erase(tokens.begin() + i - 1);
		i -= 1;
	}
	
	return tokens;
}
