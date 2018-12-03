#!/usr/bin/env python3

repl = [
    "A", "B", "C",
    "AA", "AB", "AC",
    "BA", "BB", "BC",
    "CA", "CB", "CC",
    "AAA", "AAB", "AAC",
    "ABA", "ABB", "ABC",
    "ACA", "ACB", "ACC",
    "BAA", "BAB", "BAC",
    "BBA", "BBB", "BBC",
    "BCA", "BCB", "BCC",
    "CAA", "CAB", "CAC",
    "CBA", "CBB", "CBC",
    "CCA", "CCB", "CCC",
]

S = input()
T = input()
best = 1000
for c in "ABC":
    for r in repl:
        m = S
        for it in range(4):
            if m == T:
                if it < best:
                    best = it
                    bests = (c + " " + r + "\n") * it
            m = m.replace(c, r)
print(bests)
