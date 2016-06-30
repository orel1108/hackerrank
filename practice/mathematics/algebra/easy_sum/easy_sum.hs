module Main where

import Control.Monad (forM_)

solve :: Integer -> Integer -> Integer
solve n m = res + r * (r + 1) `div` 2
    where
        (q, r) = divMod n m
        res    = m * (m - 1) * q `div` 2

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        nm <- getLine
        let [n, m] = map (read :: String -> Integer) $ words nm
        print $ solve n m

