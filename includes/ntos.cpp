string ntos(float f) {
	ostringstream ss;
	ss << f;
	string s(ss.str());
	
	return s;
}

string ntos(int f) {
	ostringstream ss;
	ss << f;
	string s(ss.str());
	
	return s;
}
