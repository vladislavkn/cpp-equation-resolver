#include "main.h" 

string compile_string(string s) {
	vector<token> tokens = tokenize(s);
	tokens = apply_signs(tokens); 
	tokens = move_tokens_left(tokens); 
	tokens = apply_powers(tokens);
	tokens = apply_multiplications(tokens);
	for(token t: tokens)	t.print_repr();
	
	map<float, float> tokens_map = create_tokens_map(tokens);
	start_group("TOKENS MAP");
	print_tokens_map(tokens_map);
	
	return "empty";
}

int main() {
	ifstream infile("./io/input.txt");
	ofstream outfile("./io/output.txt");
	string s;
	while(getline(infile, s))	{
		if(ENABLE_LOGGING) start_group(s);
		s = compile_string(s);
		if(ENABLE_LOGGING) {
			start_group("RESULT");
			cout << s << endl; 
		}
		outfile << s << endl;
	}
}
