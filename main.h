#define ENABLE_LOGGING true
using namespace std;

// Standart includes
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cmath> 

// Local types
#include "internals/token_type.cpp"

// Local includes
#include "includes/formatio.cpp" 

// Enchanters
#include "internals/enchanters/apply_signs.cpp"
#include "internals/enchanters/move_tokens_left.cpp"
// #include "internals/enchanters/apply_powers.cpp"
// #include "internals/enchanters/apply_multiplication.cpp"

// Internals
#include "internals/tokenize.cpp"
//#include "internals/resolve.cpp"

/*
	1) tokenize
	2) apply_signs
	3) apply_powers
	4) apply_multiplication
	5) move_tokens_left 
	6) resolve 
*/

