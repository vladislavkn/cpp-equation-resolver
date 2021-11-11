#include "main.h" 

string compile_string(string s) {
	int error_index = validate_string(s);
	if(error_index != -1) return "String validation error at index " + to_string(error_index);
	
	vector<token> tokens = tokenize(s); 
	
	tokens = apply_signs(tokens); 
	tokens = move_tokens_left(tokens); 
	tokens = apply_powers(tokens);
	tokens = apply_multiplications(tokens);
	LOG for(token t: tokens) t.print_repr();
	
	map<float, float> tokens_map = create_tokens_map(tokens);
	LOG start_group("TOKENS MAP");
	LOG print_tokens_map(tokens_map);
	
	vector<float> results = resolve(tokens_map);
	LOG start_group("RESOLVE");
	LOG for(float value: results) cout << value << ' ';
	LOG cout << endl;
	
	return "empty";
}

int main() {
	ifstream infile("./io/input.txt");
	ofstream outfile("./io/output.txt");
	string s;
	while(getline(infile, s))	{
		LOG start_group(s);
		s = compile_string(s);
		LOG start_group("RESULT");
		LOG	cout << s << endl; 
		outfile << s << endl;
	}
}
