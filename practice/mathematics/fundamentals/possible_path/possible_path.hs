module Main where

import Control.Monad (forM_)

solve :: Integer -> Integer -> Integer -> Integer -> String
solve a b x y = do
    if s == t
        then "YES"
        else "NO"
    where
        s = gcd a b
        t = gcd x y

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        d <- getLine
        let [a, b, x, y] = map (read :: String -> Integer) $ words d
        putStrLn $ solve a b x y

