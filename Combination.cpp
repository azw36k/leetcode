/* ---- Pascal's Triangle ---- */
for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
        cnt[i][j] = (cnt[i - 1][j] + cnt[i - 1][j - 1]) % MOD;
/* ---- Combination ---- */
