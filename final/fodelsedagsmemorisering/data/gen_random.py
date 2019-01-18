from datetime import date
import random
import string
import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


random_names = set()
def random_name():
    name = random.choice(string.ascii_uppercase)
    name += ''.join(random.choice(string.ascii_lowercase) for i in range(9))
    return name


def random_date():
    if random.randrange(50) == 0:
        return '29/02'
    start_date = date(2018, 1, 1).toordinal()
    end_date = start_date + 365 * 4 + 1
    random_date = date.fromordinal(random.randint(start_date, end_date))
    return random_date.strftime('%d/%m')


random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('N', 2000))
max_c = int(cmdlinearg('maxC', 10**5))
same = int(cmdlinearg('same', 0))

assert max_c >= n, 'maxC too small'

names = [random_name() for i in range(n)]
cs = random.sample(range(max_c), n)
common = set(random.sample(range(n), same))
common_date = random_date()

print(n)
for i, name in enumerate(names):
    d = common_date if i in common else random_date()
    print("{} {} {}".format(name, cs[i], d))
