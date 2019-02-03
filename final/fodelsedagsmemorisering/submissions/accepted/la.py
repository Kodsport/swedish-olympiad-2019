N = input()
friends = {}
for _ in range(N):
    name, prio, day = raw_input().split()
    prio = int(prio)
    if day in friends:
        if prio > friends[day][1]:
            friends[day] = (name,prio)
    else:
        friends[day] = (name,prio)
out = [friends[d][0] for d in friends]
out.sort()
print len(out)
print '\n'.join(out)
