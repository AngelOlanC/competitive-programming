def expected_time_to_exit(r, c, p):
    # Initialize the dp table
    dp = [[0] * c for _ in range(r)]
    
    # Base case: Destination point
    dp[r-1][c-1] = 0  # No time needed at the destination
    
    # Fill the dp table backwards
    for i in range(r-1, -1, -1):
        for j in range(c-1, -1, -1):
            if i == r-1 and j == c-1:
                continue  # Skip the destination point
            
            move_down = move_right = float('inf')
            
            # If we can move down
            if i < r-1:
                move_down = 0.5 * dp[i+1][j] + 0.5 * (dp[i+1][j] + p / 2)
            
            # If we can move right
            if j < c-1:
                move_right = 0.5 * dp[i][j+1] + 0.5 * (dp[i][j+1] + p / 2)
            
            # Take the minimum of moving down or right
            dp[i][j] = min(move_down, move_right)
    
    # Return the expected time from the start point
    return dp[0][0]

# Test the samples:
print(f"Sample Output 1: {expected_time_to_exit(2, 3, 8):.6f}")  # Should print around 2.875
print(f"Sample Output 2: {expected_time_to_exit(5, 5, 5):.6f}")  # Should print around 2.432
