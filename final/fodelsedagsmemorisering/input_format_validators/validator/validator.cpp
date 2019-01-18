#include "validator.h"
#include <set>

int maxDayInMonth[13] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int readTwoDigits() {
  char a = Char();
  assert(a >= '0' && a <= '9');
  char b = Char();
  assert(b >= '0' && b <= '9');

  int ret = (a - '0') * 10 + (b - '0');
  return ret;
}

void readDate() {
  int day = readTwoDigits();
  Char('/');
  int month = readTwoDigits();
  assert(month >= 1 && month <= 12);
  assert(day >= 1 && day <= maxDayInMonth[month]);
}

void run() {
  /*
   * Below is code for fodelsedagsmemorisering
   **/
  int nMax = Arg("nMax");
  int cMax = Arg("cMax");
  assert(nMax <= cMax);

  int N = Int(1, nMax);
  Endl();

  set<string> seenNames;
  set<int> seenCs;

  for (int i = 0; i < N; i++) {
    // Name
	string name;
    char c = IO::Char();
    assert(c >= 'A' && c <= 'Z');
	name += c;
    while ((c = Char()) != ' ') {
      assert('a' <= c && c <= 'z');
      name += c;
    }
    assert(!seenNames.count(name));
    seenNames.insert(name);

    // Space eaten by Char()

    int C = Int(0, cMax);
    assert(!seenCs.count(C));
    seenCs.insert(C);

    Space();

    readDate();

    Endl();
  }
}
