module Main where

solve s n = solve' (s, 0) n 0
    where
        solve' (s, cnt) n pos
            | pos == n - 2 = cnt
            | otherwise    = solve' scnt n (pos + 1)
                where
                    triplet = take 3 (drop pos s)
                    scnt    = if triplet == "010" then (take pos s ++ "011" ++ (drop (pos + 3) s), cnt + 1) else (s, cnt)

main :: IO ()
main = do
    n <- readLn :: IO Int
    b <- getLine
    print $ solve b n

