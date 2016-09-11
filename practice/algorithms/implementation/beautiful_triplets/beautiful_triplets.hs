module Main where

import qualified Data.Set as Set

solve :: [Int] -> Int -> Set.Set Int -> Int -> Int
solve [] _ _ res = res
solve (x:a) d values res
    | Set.member (x + d) values && Set.member (x + 2 * d) values = solve a d values (res + 1)
    | otherwise                                                  = solve a d values res

main :: IO ()
main = do
    nd <- getLine
    a' <- getLine
    let [n, d] = map (read :: String -> Int) $ words nd
        a      = map (read :: String -> Int) $ words a'
    print $ solve a d (Set.fromList a) 0

