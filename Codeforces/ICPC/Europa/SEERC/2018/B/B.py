a, b, c, n = map(int,input().split())

if n < 3:
  print(0)
  exit()

factor = 1
if a == b and b == c:
  factor = 6
elif a == b or a == c or b == c:
  factor = 2

mod = 2**64

if n % 2 == 0:
  ans = n*((n//2-1)*(n//2+2)+(n-2))
else:
  ans = n*(n//2)*(n//2+1)

ans //= factor
ans %= mod
print(int(ans))