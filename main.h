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

// Internals
#include "internals/tokenize.cpp"
#include "internals/apply_signs.cpp"
#include "internals/move_tokens_left.cpp"

#include "internals/analyze.cpp"
#include "internals/resolve.cpp"
