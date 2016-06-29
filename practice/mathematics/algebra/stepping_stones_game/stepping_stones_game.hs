module Main where

import Control.Monad (forM_)

isqrt :: Integer -> Integer
isqrt = floor . sqrt . fromInteger

solve k n
    | k * (k + 1) < 2 * n  = solve (k + 1) n
    | k * (k + 1) == 2 * n = "Go On Bob " ++ (show k)
    | otherwise            = "Better Luck Next Time"

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        let k = isqrt (2 * n)
        putStrLn $ solve k n

