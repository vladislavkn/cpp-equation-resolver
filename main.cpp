#include "main.h" 

string compile_string(string s) {
	vector<token> tokens = tokenize(s);
	tokens = apply_signs(tokens);
	tokens = move_tokens_left(tokens);
	
	for(token t: tokens) {
		t.print_repr();
	}
//	map<float, float> hashmap = build_hashmap(tokens);
		return "empty";
//	return resolve(hashmap);
}

int main() {
	ifstream infile("./io/input.txt");
	ofstream outfile("./io/output.txt");
	string s;
	while(getline(infile, s))	{
		if(ENABLE_LOGGING) start_group("START STRING " + s);
		s = compile_string(s);
		if(ENABLE_LOGGING) {
			start_group("RESULT");
			cout << s << endl;
			end_group();
		}
		outfile << s << endl;
	}
}