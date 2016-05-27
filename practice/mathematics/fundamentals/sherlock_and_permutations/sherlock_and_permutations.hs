module Main where

factorial :: Integer -> Integer
factorial n
    | n == 0 = 1
    | n > 0  = n * (factorial (n - 1))
    
coef n k m = (num `div` den) `mod` m
    where
        num = factorial n
        den = factorial (n - k) * factorial k

solve :: [Integer] -> Integer
solve [n, k] = coef (n + k - 1) (k - 1) 1000000007

main :: IO ()
main = do
    t <- readLn :: IO Int
    l <- getContents
    let d = map (map (read :: String -> Integer) . words) $ lines l
    putStr $ unlines $ map (show . solve) d

