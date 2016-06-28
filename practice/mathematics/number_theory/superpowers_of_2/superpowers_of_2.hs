module Main where

solve a b = solve' a b 2
    where
        solve' a b c
            | a == 0    = c `mod` b
            | otherwise = solve' (a - 1) b (c * c `mod` b)

main :: IO ()
main = do
    ab <- getLine
    let [a, b] = map (read :: String -> Integer) $ words ab
    print $ solve a b

