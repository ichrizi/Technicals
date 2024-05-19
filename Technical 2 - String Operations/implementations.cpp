#include <iostream>
#include <string_operations.h>

int string_length(const char *str) {
	const char *ptr = str;
	while (*ptr != '\0') {
		ptr++;
		}
	return ptr - str;
	}

int string_compare(const char *s1 , const char *s2) {
	while ( *s1 == *s2) {
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
		}
		return *s1 - *s2;
	}
	
void string_concatenate(char *s1, const char *s2);

