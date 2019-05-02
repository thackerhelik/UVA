#did in python because wanted factorial(26) C++ int128 should be fine
#Append first character. For every index from 2 to last, we have index positions to consider for placing the character
#Place the character and subtract the above values of above positions eg if i am placing at position 2, then positions 0 and 1 result in some values that need to be subtracted.
#factorial becomes factorial / index

import math

t = int(input())

while t>0:
  s = input()
  number = int(input())
  ans = []
  ans.append(s[0])
  fact = math.factorial(len(s))
  for index in range(2, len(s) + 1):
    fact = fact // index
    position = (number - 1) // fact
    number = number - position*fact
    ans.insert(position, s[index - 1])
  for i in ans:
    print(i, end = "")
  print()
  t = t - 1
