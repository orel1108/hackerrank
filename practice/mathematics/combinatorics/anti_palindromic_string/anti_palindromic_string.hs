module Main where

import Control.Monad (forM_)

p :: Integer
p = 10 ^ 9 + 7

pow_mod :: Integer -> Integer -> Integer
pow_mod m n = pow_mod_util m n 1
    where
        pow_mod_util m n r
            | n == 0         = r
            | n `mod` 2 == 1 = pow_mod_util (m * m `mod` p) (n `div` 2) (r * m `mod` p)
            | otherwise      = pow_mod_util (m * m `mod` p) (n `div` 2) r

solve :: Integer -> Integer -> Integer
solve n m
    | n == 1    = m
    | n == 2    = m * (m - 1) `mod` p
    | otherwise = total * m * (m - 1) `mod` p
    where
        total = pow_mod (m - 2) (n - 2)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        nm <- getLine
        let [n, m] = map (read :: String -> Integer) $ words nm
        print $ solve n m

