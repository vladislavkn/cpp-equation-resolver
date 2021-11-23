using namespace std;

bool is_digit(char c) {
	return (c >= '0') && (c <= '9');
}

bool is_divider(char c) {
	return c == '.' || c == ',';
}

bool is_operator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '=' || c == '^';	
}

// Pull number from a string and update current symbol index
float pull_number(string s, int& i) {
	float number = 0;
	bool has_point = false;
	int offset = 0;
	for(; is_digit(s[i]) || is_divider(s[i]); i++) {
		if(has_point) offset += 1;
		if(is_divider(s[i])) has_point = true;
		else number = number * 10 + (s[i] - '0');
	}
	
	return number / pow(10, offset);
}

// Process string to tokens 
vector<token> tokenize(string s) {
	vector<token> tokens;
	for(int i = 0; i < s.length(); i++) {
		token t;
		if(is_operator(s[i])) {
			if(s[i] == '+') t = make_token(ADD);
			if(s[i] == '-') t = make_token(SUBSTITUTE);
			if(s[i] == '*') t = make_token(MULTIPLY);
			if(s[i] == '^') t = make_token(POWER); 
			if(s[i] == '=') t = make_token(EQUALS); 
		} else if(is_digit(s[i])) {
			t = make_token(NUMBER, pull_number(s, i));
		 	i -= 1;
		} else if(s[i] == 'x') {
			t = make_token(VARIABLE);
		}
		
		tokens.push_back(t);
	}
	
	return tokens;
}

