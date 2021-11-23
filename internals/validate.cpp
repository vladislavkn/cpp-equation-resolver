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
		
		// Validate first symbol
		if(i == 0) {
			if(!__is_char_digit(s[i]) && (s[i] != 'x')) return i;
		}
		
		// Validate middle symbols
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
		
		// Validate last symbol
		if(i == (s.length() - 1)) {
			if(!__is_char_digit(s[i]) && (s[i] != 'x')) return i;
		}
	}
	
	// Validation passed
	return -1;
}
