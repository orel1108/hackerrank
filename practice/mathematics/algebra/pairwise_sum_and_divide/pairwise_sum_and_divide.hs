module Main where

import Control.Monad (forM_)

count :: [Integer] -> (Integer, Integer) -> (Integer, Integer)
count [] (c1, c2) = (c1, c2)
count (x:a) (c1, c2)
    | x == 1    = count a (c1 + 1, c2)
    | x == 2    = count a (c1, c2 + 1)
    | otherwise = count a (c1, c2)

solve :: [Integer] -> Integer -> Integer
solve a n = cnt1 * (n - 1) + cnt2 * (cnt2 - 1) `div` 2
    where
        (cnt1, cnt2) = count a (0, 0)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n  <- readLn :: IO Integer
        a' <- getLine
        let a = map (read :: String -> Integer) $ words a'
        print $ solve a n

