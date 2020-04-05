def countWhite(s):
	i=0
	for elem in s:
		if elem == "W":
			i+=1
	return i
	
def countBlack(s):
	i=0
	for elem in s:
		if elem == "B":
			i+=1
	return i

def stringToList(s):
	list=[]
	for elem in s:
		list.append(elem)
	return list

def listToString(l):
	string=""
	for elem in l:
		string += "%s " %(elem)
	return string
	
def swap(char):
	if char == "W":
		char = "B"
	elif char == "B":
		char = "W"
	return char

def turnBlack(l):
	global k
	list = []
	for i in range(0, len(l)):
		if l[i] == "W":
			k+=1
			list.append(i+1)
			l[i] = "B"
			l[i+1] = swap(l[i+1])
	return list

def turnWhite(l):
	global k
	list = []
	for i in range(0, len(l)):
		if l[i] == "B":
			k+=1
			list.append(i+1)
			l[i] = "W"
			l[i+1] = swap(l[i+1])
	return list			

n = int(input())
BlackWhite = input()

useThis = stringToList(BlackWhite)

nB = countBlack(BlackWhite)
nW = countWhite(BlackWhite)

k = 0

if nB ==0 or nW == 0:
	print(k)
elif nB % 2 !=0 and nW % 2 != 0:
	print(-1)
elif nB % 2 == 0 and nW % 2 == 0:
	x = turnBlack(useThis)
	print(k)
	print(listToString(x))
elif nB % 2 == 0 and nW % 2 !=0:
	y = turnWhite(useThis)
	print(k)
	print(listToString(y))
elif nB % 2 != 0 and nW % 2 == 0:
	z = turnBlack(useThis)
	print(k)
	print(listToString(z))