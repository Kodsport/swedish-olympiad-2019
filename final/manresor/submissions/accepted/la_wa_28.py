import sys
sys.setrecursionlimit(2*10**5)

#Returns minimal cost for the trips trip,...,N-1 
def minimal_cost(trip,include_discounts=True):
    if DP[trip] != None: return DP[trip]
    min_cost = INF
    for validity_time,price in zip(g,p):
        if d[trip] + validity_time > d[-1]: 
            min_cost = min(min_cost,price)
        else:
            min_cost = min(min_cost,price+minimal_cost(
                next_trip[d[trip]+validity_time],include_discounts))
    if include_discounts and prev_discount[trip] != -1:
        discount_day = prev_discount[trip]
        for validity_time,price in zip(g,p):
            if discount_day + validity_time <= d[trip]: continue
            if discount_day + validity_time > d[-1]: 
                min_cost = min(min_cost,price/2)
            else:
                min_cost = min(min_cost,price/2+minimal_cost(
                    next_trip[discount_day+validity_time],include_discounts))

    DP[trip] = min_cost
    return min_cost

INF = 10**20
N,M,K = map(int,raw_input().split())
d = map(int,raw_input().split())
g = map(int,raw_input().split())
p = map(int,raw_input().split())
r = map(int,raw_input().split())

#next_trip[day] = index of the next trip in d.
next_trip = [-1]
index = 0
for i in range(1,d[-1]+1):
    next_trip.append(index)
    if i == d[index]: index += 1
assert index == N, 'next_trip is weird'

prev_discount = []
current_discount_index = 0
discount_day = -1
current_trip = 0
for day in range(1,d[-1]+1):
    if current_discount_index < K and r[current_discount_index]==day:
        discount_day = day
        current_discount_index += 1
    if d[current_trip] == day:
        prev_discount.append(discount_day)
        current_trip += 1
assert len(prev_discount) == N, 'prev_discount is weird'

DP = [None]*N
print minimal_cost(0,False)
