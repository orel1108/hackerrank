if (dynamic_cast<Fireball*>(spell))
{
    dynamic_cast<Fireball*>(spell)->revealFirepower();
}
else if (dynamic_cast<Frostbite*>(spell))
{
    dynamic_cast<Frostbite*>(spell)->revealFrostpower();
}
else if (dynamic_cast<Thunderstorm*>(spell))
{
    dynamic_cast<Thunderstorm*>(spell)->revealThunderpower();
}
else if (dynamic_cast<Waterbolt*>(spell))
{
    dynamic_cast<Waterbolt*>(spell)->revealWaterpower();
}
else
{
    string s = spell->revealScrollName();
    string w = SpellJournal::journal;
    int m = s.size();
    int n = w.size();
    int dp[m + 1][n + 1];

    for (int row = 0; row <= m; ++row)
    {
        for (int col = 0; col <= n; ++col)
        {
            if (row == 0 || col == 0)
            {
                dp[row][col] = 0;   
            }
            else if (s[row - 1] == w[col - 1])
            {
                dp[row][col] = dp[row - 1][col - 1] + 1;   
            }
            else
            {
                dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);   
            }
        }
    }
    cout << dp[m][n] << endl;
}

