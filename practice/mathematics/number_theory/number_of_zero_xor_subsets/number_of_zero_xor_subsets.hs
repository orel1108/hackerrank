module Main where

import Control.Monad (forM_)

md = 10 ^ 9 + 7

pow_mod a d m = pow_mod' a d m 1
    where
        pow_mod' a d m r
            | d == 0         = r
            | d `mod` 2 == 1 = pow_mod' (a * a `mod` m) (d `div` 2) m (r * a `mod` m)
            | otherwise      = pow_mod' (a * a `mod` m) (d `div` 2) m r

count :: Integer -> Integer
count n = pow_mod 2 d md
    where
        d = (pow_mod 2 n (md - 1) - n) `mod` (md - 1)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        print $ count n

