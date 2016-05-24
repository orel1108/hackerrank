module Main where

main :: IO ()
main = do
    a <- getLine
    let [r, c] = map (read :: String -> Integer) $ words a
        r1 = r - 1
        c1 = c - 1
        t = 10 * (r1 `div` 2) + (r1 `mod` 2) + c1 * 2
    print t

