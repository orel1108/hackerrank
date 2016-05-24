module Main where

solve :: Integer -> Integer
solve n = (p * p) `mod` m
    where 
        m = 1000000007
        p = n `mod` m

main :: IO ()
main = do
    t <- readLn :: IO Int
    d <- getContents
    putStr $ unlines $ map (show . solve . (read :: String -> Integer)) $ lines d

