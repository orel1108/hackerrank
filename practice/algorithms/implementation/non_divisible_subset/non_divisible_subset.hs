module Main where

import qualified Data.Map as Map
import qualified Data.Vector as Vec
counter :: [Int] -> Int -> Map.Map Int Int
counter a k = foldr (\key acc -> Map.insertWith (+) (key `mod` k) 1 acc) (Map.fromList [(x, 0) | x <- [0..k - 1]]) a

solve pos freq k r
    | pos == k `div` 2 + 1 = r
    | otherwise            = solve (pos + 1) freq k r'
    where
        r' = max (freq Vec.! pos) (freq Vec.! (k - pos)) + r

main :: IO ()
main = do
    param <- getLine
    a_tmp <- getLine
    let [n, k] = map (read :: String -> Int) $ words param
        a = map (read :: String -> Int) $ words a_tmp
        c = Map.elems $ counter a k
        r = if c !! 0 > 0 then 1 else 0
        h = k `div` 2
        res' = solve 1 (Vec.fromList c) k r
        res = if (even k) && (c !! h > 1) then res' - (c !! h - 1) else res'
    print res

