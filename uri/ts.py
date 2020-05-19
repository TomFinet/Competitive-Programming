import sys
import heapq
from itertools import combinations

f1 = open('outpy.txt', 'w')

def f(A):
  mag_counts = {}

  for x in A:
    if x in mag_counts:
      mag_counts[x] = mag_counts[x] + 1
    else:
      mag_counts[x] = 1

  q = []

  seen = set()

  for comb in combinations(A, 3):
    sorted_comb = tuple(sorted(comb))
    if not sorted_comb in seen:
      (a, b, c) = sorted_comb
      heapq.heappush(q, (a, (b-a, b), (c-a, c), a))
    seen.add(sorted_comb)

  while q:
    (t, (ba, b), (ca, c), prev) = heapq.heappop(q)

    # f1.write(str(t) + " ")
    # f1.write(str(b) + " ")
    # f1.write(str(ba) + " ")
    # f1.write(str(c) + " ")
    # f1.write(str(ca) + " ")
    # f1.write(str(prev) + "\n")

    if ba == 0 and ca == 0:
      return t

    for mag in mag_counts.keys():
      # Check that the magnitude is available
      # and the same singer is not repeating.
      [three, two] = [3, 2] if mag != prev else [4, 3]
      if mag == b == c and mag_counts[mag] < three:
        continue
      elif mag == b and mag_counts[mag] < two:
        continue
      elif mag == c and mag_counts[mag] < two:
        continue
      elif mag == prev and mag_counts[mag] < 2:
        continue

      m = min(mag, ba, ca)

      if m == mag:
        heapq.heappush(q, (t + m, (ba-m, b), (ca-m, c), m))
      elif m == ba:
        heapq.heappush(q, (t + m, (mag-m, mag), (ca-m, c), b))
      else:
        heapq.heappush(q, (t + m, (mag-m, mag), (ba-m, b), c))

  return float('inf')


f1 = open('outpy.txt', 'w')
t = int(input())
while t > 0:
  n = int(input())
  singers = [int(i) for i in input().split()]
  f1.write(str(f(singers)) + "\n")
  t -= 1

f1.close()