module Main where

import qualified Data.Vector as V

positions :: Int -> [(Int, Int)]
positions n = [(i, j) | i <- [0..n - 2], j <- [i + 1..n - 1]]

check :: Int -> Int -> Int -> Int
check ai aj k
    | (ai + aj) `mod` k == 0 = 1
    | otherwise              = 0

solve :: V.Vector Int -> [(Int, Int)] -> Int -> Int
solve _ [] _ = 0
solve a p k  = check (a V.! (fst pos)) (a V.! (snd pos)) k + (solve a (tail p) k)
    where
        pos = head p

main :: IO ()
main = do
    param  <- getLine
    a_temp <- getLine
    let [n, k] = map (read :: String -> Int) $ words param
        a = map (read :: String -> Int) $ words a_temp
    print $ solve (V.fromList a) (positions n) k

