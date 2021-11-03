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

bool is_tokentype_sign(token t) {
	return t.type == ADD || t.type == SUBSTITUTE;
}

bool is_tokentype_operation(token t) {
	return t.type == MULTIPLY || t.type == POWER;
}

token make_token(TOKEN_TYPE _type=TOKEN_TYPE::VOID, float _value=1) {
	token t;
	t.value = _value;
	t.type = _type;
	t.power =  (_type == VARIABLE) ? 1 : 0;
	return t;
	}
