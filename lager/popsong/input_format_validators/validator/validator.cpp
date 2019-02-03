#include "validator.h"

void run() {
	int len = 0;
	char c;
	while ((c = Char()) != '\n') {
		assert(c == '_' || ('a' <= c && c <= 'z'));
		len++;
	}
	int maxlen = Arg("n");
	assert(2 <= len && len <= maxlen);
}
