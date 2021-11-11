#include "main.h" 

string compile_string(string s) {
	LOG start_group(s);
	// Validate string
	int error_index = validate_string(s);
	if(error_index != -1) return "String validation error at index " + to_string(error_index);
	
	// Tokenize string
	vector<token> tokens = tokenize(s); 
	
	// Enchant tokens (Simplify sequence)
	tokens = apply_signs(tokens); 
	tokens = move_tokens_left(tokens); 
	tokens = apply_powers(tokens);
	tokens = apply_multiplications(tokens);
	LOG for(token t: tokens) t.print_repr();
	
	// Convert tokens to hashmap
	map<float, float> tokens_map = create_tokens_map(tokens);
	LOG start_group("TOKENS MAP");
	LOG print_tokens_map(tokens_map);
	
	// Resolve the equation
	vector<float> results = resolve(tokens_map);
	LOG start_group("RESOLVE");
	LOG for(float value: results) cout << value << ' ';
	LOG cout << endl;
	
	// Return stringified results
	LOG start_group("RESULT"); 
	if(results.size() == 0) return "No roots";
	
	string stringified_results;
	for(float value: results) stringified_results += "x=" + ftos(value) + "; ";
	return stringified_results;
}

int main() {
	ifstream infile("./io/input.txt");
	ofstream outfile("./io/output.txt");
	string s;
	
	while(getline(infile, s))	{
		s = compile_string(s);
		LOG	cout << s << endl;
		outfile << s << endl;
	}
	printf("Resolving completed\n");
}
