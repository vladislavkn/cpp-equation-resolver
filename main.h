#define ENABLE_LOGGING true
#define LOG if(ENABLE_LOGGING)
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
#include "includes/maputils.cpp" 

// Enchanters
#include "internals/enchanters/apply_signs.cpp"
#include "internals/enchanters/move_tokens_left.cpp"
#include "internals/enchanters/apply_powers.cpp"
#include "internals/enchanters/apply_multiplications.cpp"
#include "internals/enchanters/create_tokens_map.cpp"

// Resolvers
#include "internals/resolvers/resolve_power1_0.cpp"

// Internals
#include "internals/tokenize.cpp"
#include "internals/validate.cpp"
#include "internals/resolve.cpp"
 

