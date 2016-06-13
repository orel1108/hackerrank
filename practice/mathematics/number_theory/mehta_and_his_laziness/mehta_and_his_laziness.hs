module Main where

import Control.Monad (forM_)
import Text.Printf (printf)

squares :: [Int]
squares = [x * x | x <- [2,4..1000]]

isqrt :: Int -> Int
isqrt = floor . sqrt . fromIntegral

num_divisors :: Int -> Int
num_divisors n = c - 1
    where
        r  = isqrt n
        d  = filter (\v -> n `mod` v == 0) [1..r]
        c' = 2 * (length d)
        c  = if r * r == n then c' - 1 else c'

even_squares_divs :: Int -> Int
even_squares_divs n = length $ filter (\s -> n `mod` s == 0 && n > s) squares

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        let ne = even_squares_divs n
            nd = num_divisors n
            d  = gcd ne nd
        if ne == 0
            then print 0
            else printf "%d/%d\n" (ne `div` d) (nd `div` d)

