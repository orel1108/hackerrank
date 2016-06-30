module Main where

import Control.Monad (forM_)

log2 :: Integer -> Int
log2 n = log2' n 0
    where
        log2' n r
            | n > 0     = log2' (n `div` 2) (r + 1)
            | otherwise = r - 1

solve :: Integer -> Int
solve n = (rem1 * rem2) `mod` 10
    where
        l = log2 n
        rem1 = if n `mod` 2 == 0 then 1 else 5
        rem2 = if l == 0 then 2 else (6 * l) `mod` 10

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        print $ solve n

