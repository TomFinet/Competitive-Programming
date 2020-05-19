import sys
import heapq
from itertools import combinations

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


n = int(input())
singers = [int(i) for i in input().split()]
print(f(singers)) 