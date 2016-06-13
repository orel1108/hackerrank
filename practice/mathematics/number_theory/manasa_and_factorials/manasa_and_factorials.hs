module Main where

import Control.Monad (forM_)

count :: Integer -> Integer -> Integer
count p n
    | n < p     = 0
    | otherwise = count p d + d
    where d = n `div` p

bsearch :: Integer -> Integer
bsearch n = bsearch' n 0 (5 * n)
    where bsearch' n left right
            | right - left > 1 = if count 5 mid < n then bsearch' n mid right else bsearch' n left mid
            | otherwise        = right
            where mid = (left + right) `div` 2

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        print $ bsearch n

