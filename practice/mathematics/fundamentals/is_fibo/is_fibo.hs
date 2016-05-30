module Main where

import Control.Monad (forM_)

isqrt :: Integer -> Integer
isqrt = floor . sqrt . fromIntegral

is_square :: Integer -> Bool
is_square n = if n == r ^ 2 then True else False
    where
        r = isqrt n

is_fib :: Integer -> String
is_fib n
    | a1 || a2  = "IsFibo"
    | otherwise = "IsNotFibo"
    where
        a  = n ^ 2
        a1 = is_square (5 * a - 4)
        a2 = is_square (5 * a + 4)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        putStrLn $ is_fib n

