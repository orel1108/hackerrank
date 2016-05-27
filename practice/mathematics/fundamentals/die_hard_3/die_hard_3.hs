module Main where

import Control.Monad (forM_)

solve' :: Int -> Int -> Int -> Int -> String
solve' a b c d
    | d > 0 = if d == c
                then "YES" 
                else if d < a
                        then solve' a b c (b - (a - d))
                        else solve' a b c (d - a)
    | otherwise = "NO"

solve :: Int -> Int -> Int -> String
solve a b c
    | a' == c || b' == c = "YES"
    | otherwise          = solve' a' b' c (b' - a')
    where
        a' = min a b
        b' = max a b

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        l <- getLine
        let [a, b, c] = map (read :: String -> Int) $ words l
        putStrLn $ solve a b c

