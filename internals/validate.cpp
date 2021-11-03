string __acceptable_chars = "x.,0123456789+-*^=";
bool __is_char_acceptable(char c) {
	for(int i = 0; i < __acceptable_chars.length(); i++)
		if(c == __acceptable_chars[i]) return true;
	return false;
}

bool __is_char_digit(char c) {
	return (c >= '0') && (c <= '9');
}

int validate_string(string s) { 
	for(int i = 0; i < s.length(); i++) {
		if(!__is_char_acceptable(s[i])) return i;
		
		if(i == 0) {
			if((s[i] == '.') || (s[i] == '=')) return i;
		}
		
		if((i > 0) && i < (s.length() - 1)) {
			if((s[i] == '.') && !(__is_char_digit(s[i-1]) || __is_char_digit(s[i+1]))) return i;
			if(((s[i] == '*') || (s[i] == '^')) && (s[i+1] == '*' || s[i+1] == '^')) return i;
			if((s[i] == '=') && (
				(!__is_char_digit(s[i-1]) && (s[i-1] != 'x')) || 
				(!__is_char_digit(s[i+1]) && (s[i+1] != 'x') && (s[i+1] != '-') && (s[i+1] != '+'))
			)) return i;
			if(s[i] == '*' && (!__is_char_digit(s[i+1]) && (s[i+1] != 'x'))) return i;
			if(s[i] == '^' && (!__is_char_digit(s[i+1]))) return i;
		}
		
		if(i == (s.length() - 1)) {
			if((s[i] == '.') || (s[i] == '=')) return i;
		}
	}
	
	return -1;
}

//bool validate_tokens(vector<token> tokens) {
//	for(int i = 1; i < tokens.size(); i++) { 
//		// No validation rules
//	}
//	
//	return true;
//} 
