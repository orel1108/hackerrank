module Main where

import qualified Data.Vector as V

solve :: V.Vector Int -> [Int] -> String
solve ar [x, y]
    | x == y = solve'  ar x
    | x /= y = solve'' ar x
    where
        solve'  ar x
            | ar V.! (x - 1) `mod` 2 == 1 = "Odd"
            | otherwise                   = "Even"
        solve'' ar x
            | ar V.! (x - 1) `mod` 2 == 0 && ar V.! x /= 0 = "Even"
            | otherwise                                    = "Odd"

main :: IO ()
main = do
    n <- readLn :: IO Int
    ta <- getLine
    q <- readLn :: IO Int
    
    let a = map (read :: String -> Int) $ words ta
        ar = V.fromList a
    
    t <- getContents
    putStr $ unlines $ map (solve ar) $ map (map (read :: String -> Int) . words) $ lines t
