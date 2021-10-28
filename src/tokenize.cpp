using namespace std;

enum TOKEN_TYPE {
	ADD,
	SUBSTITUTE,
	MULTIPLY,
	POWER,
	VARIABLE,
	NUMBER,
	VOID,
	EQUALS
};

struct token {
	TOKEN_TYPE type;
	float value=1;
	float power=1;
	static token make(TOKEN_TYPE _type=TOKEN_TYPE::VOID, float _value=1) {
		token t;
		t.value = _value;
		t.type = _type;
		return t;
	}
	void print_repr() {
	  string type_name;
		if(type == ADD)cout << "ADD";
		if(type == SUBSTITUTE) cout << "SUBSTITUTE";
		if(type == MULTIPLY) cout << "MULTIPLY";
		if(type == POWER) cout << "POWER";
		if(type == VARIABLE) cout << "VARIABLE" << "<" << value << ", " <<  power << ">";
		if(type == NUMBER) cout << "NUMBER" << "<" << value << ">";
		if(type == VOID) cout << "VOID";
		if(type == EQUALS) cout << "EQUALS";
		
		cout << endl;
	}
};

bool is_digit(char c) {
	return (c >= '0') && (c <= '9');
}

bool is_divider(char c) {
	return c == '.' || c == ',';
}

bool is_operator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '=' || c == '^';	
}

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

vector<token> tokenize(string s) {
	vector<token> tokens;
	for(int i = 0; i < s.length(); i++) {
		token t;
		if(is_operator(s[i])) {
			if(s[i] == '+') t = token::make(ADD);
			if(s[i] == '-') t = token::make(SUBSTITUTE);
			if(s[i] == '*') t = token::make(MULTIPLY);
			if(s[i] == '^') t = token::make(POWER); 
			if(s[i] == '=') t = token::make(EQUALS); 
		} else if(is_digit(s[i])) {
			t = token::make(NUMBER, pull_number(s, i));
		 	i -= 1;
		} else if(s[i] == 'x') {
			t = token::make(VARIABLE);
		}
		
		tokens.push_back(t);
	}
	
	return tokens;
}

vector<token> move_left(vector<token> tokens) {
	int eq_index = -1;
	for(int i = 0; i < tokens.size(); i++) {
		if(tokens[i].type == EQUALS) {
			eq_index = i;
			if((tokens[i+1].type != ADD) || (tokens[i+1].type != SUBSTITUTE))
				tokens[i].type = ADD;
		}
		if(eq_index >= 0) {
			if(tokens[i].type == ADD) tokens[i].type = SUBSTITUTE;
			else if(tokens[i].type == SUBSTITUTE) tokens[i].type = ADD;
		}
	}
	
	return tokens;
}

