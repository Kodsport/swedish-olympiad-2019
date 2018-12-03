n, m, k = map(int, input().split())

meals = [[0,0] for i in range(m)]

choices = list(map(int, input().split()))

for meal in choices:
   meals[meal-1][1] += 1

costIn = list(map(int, input().split()))
for i,cost in enumerate(costIn):
   meals[i][0] = cost

#Sortera i fallande prisordning
meals.sort()
meals.reverse()

#Vår stack där vi lägger rätter som inte parats ihop än
freeMeals = []

#Lista på alla "optimala" byten
swaps = []

for i in range(m):
   p = meals[i][1] #Antal personer som valt denna rätt
   c = meals[i][0] #Priset för denna rätt
   if p == 0: #Ifall ingen valt denna rätt, lägg till i stacken
      freeMeals.append(c) 
   else:
      #Räkna med den här rätten som en av de k unika
      k -= 1

   #Så länge det finns saker i stacken och det finns personer,
   #para ihop de och lägg till bytet i swaps.
   while len(freeMeals)>0 and p>1:
      swaps.append(freeMeals.pop()-c)
      p -= 1

#Ifall det inte finns tillräckligt många byten att göra
if len(swaps) < k:
   print(-1)
else:
   #Välj ut de k billigaste bytena.
   swaps.sort()

   ans = 0;

   for i in range(k):
      ans+=swaps[i]
   print(ans)