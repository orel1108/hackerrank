module Main where

import Data.List (sort)

max_diff c = maximum $ zipWith (\a b -> (b - a) `div` 2) (init c) (tail c)

main :: IO ()
main = do
    nm <- getLine
    c' <- getLine
    let [n, m] = map (read :: String -> Int) $ words nm
        c      = sort $ map (read :: String -> Int) $ words c'
        res    = max (head c) (n - 1 - (last c))
    if m == 1
        then print res
        else print $ max res (max_diff c)

