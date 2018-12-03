import sys

total_score = 0
for line in sys.stdin.readlines():
    _, score = line.split()
    total_score += float(score)
total_score = min(total_score, 100)
print "AC %f" % total_score
