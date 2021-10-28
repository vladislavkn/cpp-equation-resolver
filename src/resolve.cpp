/*
	Variant 1:
	- Tokens:  VARIABLE<a, b> ADD/SUBSTITUTE NUMBER<c>
	- Hashmap: { {0: c}, {b: a} }
	- Math:    ax^b=c
	
	Variant 2:
	- Tokens:  VARIABLE<a, 2> ADD/SUBSTITUTE VARIABLE<b, 1> ADD/SUBSTITUTE NUMBER<c>
	- Hashmap: { {0: c}, {1: b}, {2: a} }
	- Math:    ax^2+bx+c=0
	
	Variant 2:
	- Tokens:  VARIABLE<a, 4> ADD/SUBSTITUTE VARIABLE<b, 2> ADD/SUBSTITUTE NUMBER<c>
	- Hashmap: { {0: c}, {2: b}, {4: a} }
	- Math:    ax^4+bx^2+c=0
*/
using namespace std;

template <typename K=float, typename V=float>
bool map_has_key(map<K, V> hashmap, K key) {
	return hashmap.find(key) != hashmap.end();
}

template <typename K=float, typename V=float>
vector<K> get_map_keys(map<K, V> m) {
	vector<K> keys;
	for(pair<K, V> p: m) keys.push_back(p.first);
	return keys;
} 

bool __check_variant_1(map<float, float> hashmap) {
	return (hashmap.size() == 2) && map_has_key(hashmap, (float)0);
}

bool __check_variant_2(map<float, float> hashmap) {
	return (hashmap.size() == 3) && map_has_key(hashmap, (float)0) && map_has_key(hashmap, (float)1) && map_has_key(hashmap, (float)2);
}

bool __check_variant_3(map<float, float> hashmap) {
	return (hashmap.size() == 3) && map_has_key(hashmap, (float)0) && map_has_key(hashmap, (float)2) && map_has_key(hashmap, (float)4);
}

int get_evaluation_type(map<float, float> hashmap) {
	int variant = 0;
	if(__check_variant_1(hashmap)) variant = 1;
	else if(__check_variant_2(hashmap)) variant = 2;
	else if(__check_variant_3(hashmap)) variant = 3; 
	
	if(ENABLE_LOGGING) {
		start_group("CHECK EVALUATION VARIANT");
		if(variant == 0) cout << "Error: wrong variant";
		else cout << "Variant " << variant << endl;
		end_group();
	}
	
	return variant;
}

string __resolve_variant_1(map<float, float> hashmap) {
	float variable_power, result;
	vector<float> keys = get_map_keys(hashmap);
	
	for(float key: keys) if(key != 0) {
		variable_power = key;
		break;
	}
	
	if (variable_power < 1) {
		result = pow((-hashmap[0]), 1/variable_power);
		if(((int)Math.ceil(1/variable_power) % 2 == 0) && ((-hashmap[0]) < 0)) return "No x was found (x^2n<0 error)";
		return "x = " + to_string(result);
	}
	
//	if(((float)(int)variable_power == pariable_power) && ((int)(varaible_power) % 2 == 1) && (hashmap[0] > 0)) {
//		return pow(hashmap[0] )
//	}
	
//	return to_string((-hashmap[0]) / hashmap[1]);
}

string resolve(map<float, float> hashmap) {
	int variant = get_evaluation_type(hashmap);
	switch(variant) {
		case 1:
			return __resolve_variant_1(hashmap);
		default:
			return "Error: wrong type";
	}
}




