using namespace std;

int __group_divider_width = 48;

void print_header(string name) { 
	int segment_size = (__group_divider_width - 2 - name.length()) / 2;
	cout << "\n";
	for(int i = 0; i < segment_size; i++) cout << "=";
	cout << " " << name << " ";
	for(int i = 0; i < segment_size; i++) cout << "=";
	if(name.length() % 2 == 1) cout << "=";
	cout << "\n";
} 

void print_title(string str) {
	cout << str << '\n';
}

void print_row(string str) {
	cout << '\t' << str << '\n';
}
