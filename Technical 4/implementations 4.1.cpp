#include "stack_operations.h"
using namespace std;
int MinReplace(const string &braces) {
	stack<char> s;
	int replacements = 0;
	
	for (size_t i = 0; i < braces.size(); ++i) {
		char ch = braces[i];
		if(ch == '{') {
			s.push(ch);
	} else if (ch == '}') {
		if (s.empty()) {
			replacements++;
			s.push('{');
	} else {
				s.pop();
			}
		}
		
	}
	while (!s.empty()) {
		replacements++;
		s.pop();
	}
	return replacements;
}
