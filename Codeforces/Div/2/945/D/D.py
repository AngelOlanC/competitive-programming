def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    s = int(data[1])
    
    if s % 2 != 0:
      print(0)
      return

    s //= 2
    dp = [[0] * (s + 1) for _ in range(n + 1)]
    
    for i in range(s + 1):
        dp[n][i] = 1 if i == s else 0
    
    for i in range(n - 1, -1, -1):
        for j in range(s, -1, -1):
            dp[i][j] = 0
            for k in range(10):
                if j + k <= s:
                    dp[i][j] += dp[i + 1][j + k]
    
    print(dp[0][0] * dp[0][0])

if __name__ == "__main__":
    main()
