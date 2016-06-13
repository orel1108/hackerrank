module Main where

import Control.Monad (forM_)
import qualified Data.Vector as V

findNotDiv :: V.Vector Int -> Int -> Int -> Int
findNotDiv a n v = findNotDiv' a n v 0
    where
        findNotDiv' :: V.Vector Int -> Int -> Int -> Int -> Int
        findNotDiv' a n v pos
            | pos == n               = pos
            | a V.! pos `mod` v /= 0 = pos
            | otherwise              = findNotDiv' a n v (pos + 1)

findVal :: V.Vector Int -> Int -> Int -> String
findVal a n m = findVal' a n m 2
    where
        findVal' :: V.Vector Int -> Int -> Int -> Int -> String
        findVal' a n m v
            | pos == n = "NO"
            | v == m + 1 = "YES"
            | otherwise = findVal' a n m (v + 1)
            where
                pos = findNotDiv a n v

solve :: [Int] -> Int -> String
solve a n
    | m == 1 = "YES"
    | otherwise = findVal (V.fromList a) n m
    where
        m = minimum a

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n  <- readLn :: IO Int
        a' <- getLine
        let a = map (read :: String -> Int) $ words a'
        putStrLn $ solve a n

