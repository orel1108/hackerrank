module Main where

import qualified Data.Vector as V

solve :: V.Vector Integer -> Integer -> Integer -> Integer -> Integer -> Integer -> Integer -> Integer
solve a n s s1 k ps res
    | k < n + 1 = solve a n s s1 (k + 1) ps' res'
    | otherwise = res
    where
        sk = s1 - (k - 1) * s + n * ps
        ps'  = ps + (a V.! (fromInteger k - 1))
        res' = max res sk

main :: IO ()
main = do
    n <- readLn :: IO Integer
    a' <- getLine
    let a  = map (read :: String -> Integer) $ words a'
        s  = sum a
        s1 = sum $ zipWith (*) a [1..n]
        ps = a !! 0
    print $ solve (V.fromList a) n s s1 2 ps s1
    
