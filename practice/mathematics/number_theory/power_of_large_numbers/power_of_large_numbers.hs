module Main where

import Control.Monad (forM_)

p :: Integer
p = 10 ^ 9 + 7

pow_mod :: Integer -> Integer -> Integer -> Integer
pow_mod a deg m = pow_mod' a deg m 1
    where
        pow_mod' :: Integer -> Integer -> Integer -> Integer -> Integer
        pow_mod' a deg m r
            | deg == 0         = r `mod` m
            | deg `mod` 2 == 1 = pow_mod' (a * a `mod` m) (deg `div` 2) m (r * a)
            | otherwise        = pow_mod' (a * a `mod` m) (deg `div` 2) m r

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        ab <- getLine
        let [a, b] = map (read :: String -> Integer) $ words ab
        print $ pow_mod (a `mod` p) (b `mod` (p - 1)) p

