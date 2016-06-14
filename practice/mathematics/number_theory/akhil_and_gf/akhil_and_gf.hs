module Main where

import Control.Monad (forM_)

pow_mod :: Integer -> Integer -> Integer -> Integer
pow_mod a d m = pow_mod' a d m 1
    where
        pow_mod' :: Integer -> Integer -> Integer -> Integer -> Integer
        pow_mod' a d m r
            | d == 0         = r
            | d `mod` 2 == 1 = pow_mod' (a * a `mod` m) (d `div` 2) m (r * a `mod` m)
            | otherwise      = pow_mod' (a * a `mod` m) (d `div` 2) m r

solve n m = d `div` 9
    where
        d' = pow_mod 10 n (9 * m)
        d  = if d' > 0 then d' - 1 else 9 * m - 1

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        nm <- getLine
        let [n, m] = map (read :: String -> Integer) $ words nm
        print $ solve n m

