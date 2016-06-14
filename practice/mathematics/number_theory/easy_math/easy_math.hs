module Main where

import Control.Monad (forM_)
import qualified Data.Set as Set
import Data.Maybe
import Data.List (elemIndex)

count2 :: Integer -> Integer
count2 n
    | n > 0 && n `mod` 2 == 0 = 1 + count2 (n `div` 2)
    | otherwise               = 0

count5 :: Integer -> Integer
count5 n
    | n > 0 && n `mod` 5 == 0 = 1 + count5 (n `div` 5)
    | otherwise               = 0

solve :: Integer -> Integer
solve n = 2 * c
    where
        c = solve' 1 n
        solve' :: Integer -> Integer -> Integer
        solve' a n
            | a `mod` n == 0 = 1
            | otherwise      = 1 + solve' a' n
            where
                a' = (10 * a + 1) `mod` n
    
main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        let c2 = count2 n
            c5 = count5 n
            m  = max (c2 - 2) c5
            n' = n `div` (2 ^ c2 * 5 ^ c5)
        print $ solve n' + m

