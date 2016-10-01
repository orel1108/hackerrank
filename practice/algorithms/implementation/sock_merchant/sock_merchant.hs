module Main where

import qualified Data.Map as Map

counter :: [Int] -> Map.Map Int Int
counter colors = foldr (\color acc -> Map.insertWith (+) color 1 acc) Map.empty colors

solve colors n = (n - x) `div` 2
    where
        x = sum $ map (`mod` 2) (Map.elems (counter colors))

main :: IO ()
main = do
    n  <- readLn :: IO Int
    c' <- getLine
    let c = map read $ words c' :: [Int]
    print $ solve c n

