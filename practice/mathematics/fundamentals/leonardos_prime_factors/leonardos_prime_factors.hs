module Main where

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
prods  = scanl (*) 1 primes

solve :: Integer -> Int
solve n = solve' n 0
    where
        solve' n p
            | n >= (prods !! p) = solve' n (p + 1)
            | otherwise = p - 1

main :: IO ()
main = do
    n <- readLn :: IO Int
    d <- getContents
    let nums = map (read :: String -> Integer) $ lines d
    putStr $ unlines $ map (show.solve) nums

