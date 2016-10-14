module Main where

import Data.Char

to_int c
    | isUpper c = 1
    | otherwise = 0

main :: IO ()
main = do
    s <- getLine
    let n = foldr (\c acc -> acc + (to_int c)) 1 s
    print n

