module Main where

num_divisors :: Integer -> Integer
num_divisors n = foldl (\acc x -> if n `mod` x == 0 then acc + 2 else acc) 0 [1..r] - d where
    r = floor $ sqrt $ fromIntegral n
    d = if r * r == n
            then 1
            else 0

solve :: Integer -> Integer
solve n = do
    if n `mod` 2 == 1
        then 0
        else num_divisors h
    where
        h = n `div` 2

main :: IO ()
main = do
    t <- readLn :: IO Int
    l <- getContents
    let nums = map (read :: String -> Integer) $ lines l
    putStr $ unlines $ map (show . solve) nums

