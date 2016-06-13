module Main where

import Control.Monad (forM_)

isqrt :: Integer -> Integer
isqrt = floor . sqrt . fromIntegral

solve :: Integer -> String
solve n
    | a `mod` 2 == 0 = "even"
    | otherwise      = "odd"
    where
        a' = isqrt n
        a  = if a' * a' > n then a' - 1 else a'

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        putStrLn $ solve n

