module Main where

solve :: [Integer] -> Integer
solve [a, b, x]
    | 2 * p <= x            = 0
    | p < x                 = x
    | 2 * p <= 2 * k + x    = k
    | otherwise             = k + x
    where
        p = if b >= 0 then a ^ b else q
        k = p - (p `mod` x)
        q = if a > 1 then 0 else 1

main :: IO ()
main = do
    t <- readLn :: IO Int
    c <- getContents
    let d = map ((map (read :: String -> Integer)) . words) $ lines c
    putStr $ unlines $ map (show . solve) d

