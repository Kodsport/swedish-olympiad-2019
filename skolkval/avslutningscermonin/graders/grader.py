import sys

def is_int(arg):
    try:
        int(arg)
        return True
    except:
        return False


def main():
    if "ignore" in sys.argv:
        print "AC 0"
    elif "sum" in sys.argv:
        total_score = 0
        first_error = None
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            total_score += float(score)
            if verdict != "AC" and not first_error:
                first_error = verdict
        if total_score == 0 and first_error:
            print "%s 0" % first_error
        else:
            print "AC %f" % total_score
    elif "all" in sys.argv:
        total_score = 0
        for arg in sys.argv:
            if is_int(arg):
                total_score = float(arg)
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            if verdict != "AC":
                print "%s 0" % verdict
                return
        print "AC %f" % total_score
    else:
        for line in sys.stdin.readlines():
            print line

main()
