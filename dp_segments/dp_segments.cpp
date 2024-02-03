for (int len = 1; len <= n; ++len) {
    for (int start = 0; start + len <= n; ++start) {
        dp[start][start + len - 1] = min();
    }
}