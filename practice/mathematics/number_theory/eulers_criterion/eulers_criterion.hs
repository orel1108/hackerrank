module Main where

import Control.Monad (forM_)

pow_mod_util :: Integer -> Integer -> Integer -> Integer -> Integer
pow_mod_util a 0 m res = res
pow_mod_util a deg m res
    | deg `mod` 2 == 1 = pow_mod_util (a * a `mod` m) (deg `div` 2) m (res * a `mod` m)
    | otherwise        = pow_mod_util (a * a `mod` m) (deg `div` 2) m res

pow_mod :: Integer -> Integer -> Integer -> Integer
pow_mod a d p = pow_mod_util a d p 1

euler :: Integer -> Integer -> Bool
euler a p
    | x == 1 = True
    | x /= 1 = False
    where
        d = (p - 1) `div` 2
        x = pow_mod a d p

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        ap <- getLine
        let [a, p] = map (read :: String -> Integer) $ words ap
        if p == 2 || a == 0 || euler a p == True
            then putStrLn "YES"
            else putStrLn "NO"

