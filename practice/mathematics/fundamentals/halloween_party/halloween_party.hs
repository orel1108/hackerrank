module Main where

solve :: Integer -> Integer
solve n
    | n == 0 || n == 1 = 0
    | n `mod` 2 == 0   = h ^ 2
    | otherwise        = (n + 1) `div` 2 * h
    where
        h = n `div` 2

main :: IO ()
main = do
    t <- readLn :: IO Int
    g <- getContents
    let a = map (read :: String -> Integer) $ lines g
    putStr $ unlines $ map (show . solve) a

