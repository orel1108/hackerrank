module Main where

import Control.Monad (forM_)

decompose :: Integer -> Integer -> [Integer]
decompose v p
    | v > 0     = r : (decompose q p)
    | otherwise = []
    where
        (q, r) = divMod v p

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        np <- getLine
        let [n, p] = map (read :: String -> Integer) $ words np
            coeffs = decompose n p
            r      = foldr (\x acc -> (x + 1) * acc) 1 coeffs
        print $ n + 1 - r

