module Main where

import Control.Monad (forM_)

solve n
    | n `mod` 2 == 1 = 2
    | n `mod` 4 == 0 = 3
    | otherwise      = 4

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        print $ solve n

