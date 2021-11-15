#include "main.h" 

string compile_string(string s) {
	LOG print_header(s);
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
	DET print_title("TOKENS LIST");
	DET for(token t: tokens) t.print_repr("\t");
	
	// Convert tokens to hashmap
	LOG print_title("TOKENS MAP");
	map<float, float> tokens_map = create_tokens_map(tokens);
	LOG print_tokens_map(tokens_map, "\t");
	
	// Resolve the equation
	LOG print_title("RESOLVE");
	vector<float> results = resolve(tokens_map);
	DET print_results(results, "\t");
	
	// Return stringified results
	DET print_title("RESULT"); 
	if(results.size() == 0) return "No roots";
	
	string stringified_results;
	for(float value: results) stringified_results += "x=" + ntos(value) + "; ";
	return stringified_results;
}

int main() {
	ifstream infile("./io/input.txt");
	ofstream outfile("./io/output.txt");
	string s, result_string;
	int line_number = 1;
	
	while(getline(infile, s))	{
		result_string = ntos(line_number++) + ") " + compile_string(s);
		LOG	print_row(result_string);
		outfile << result_string << endl;
	}
	print_header("Resolving completed");
}
