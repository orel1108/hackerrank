module Main where

import Control.Monad (forM_)
import Data.Bits

solve' :: Integer -> Integer -> Integer
solve' i n
    | s `mod` n == 0 = s
    | otherwise      = 0
    where
        t = [if (i .&. (1 `shiftL` j)) > 0 then 9 else 0 | j <- [0..12]]
        d = [10 ^ j | j <- [0..12]]
        s = sum $ zipWith (*) t d

solve :: Integer -> Integer -> Integer
solve k n
    | k < 6000 = if s /= 0
                    then s
                    else solve (k + 1) n
    | otherwise = 0
    where s = solve' k n

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        print $ solve 1 n

