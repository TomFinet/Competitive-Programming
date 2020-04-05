n = int(input())
mapp = []
c = 0
length = 0

cities = [0 for x in range(n)]
cities[0] = 1


for x in range(1,n):
	mapp.append(sorted(list(map(int, input().split(' ')))))
print(mapp)


while cities.count(1) < n:
	c += 1
	at = 1
	for x  in range(1+c,n+1):
		if([at,x] in mapp):
			at = x
			length +=1	
			cities[x-1] = 1
	
print("%.6f"% (length/c))