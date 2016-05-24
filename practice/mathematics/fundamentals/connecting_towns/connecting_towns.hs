module Main where

import Control.Monad (forM_)

solve :: [Int] -> Int
solve a = foldr (\x acc -> (x * acc) `mod` 1234567) 1 a

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        d <- getLine
        print $ solve $ map (read :: String -> Int) $ words d

