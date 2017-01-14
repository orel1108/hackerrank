module Main where

import Control.Monad (forM_)

mult_complex_mod :: (Integer, Integer) -> (Integer, Integer) -> Integer -> (Integer, Integer)
mult_complex_mod a b m = (x, y)
    where
        x'  = fst a
        y'  = snd a
        x'' = fst b
        y'' = snd b
        x   = (x' * x'' - y' * y'') `mod` m
        y   = (x' * y'' + x'' * y') `mod` m

pow_complex_mod :: (Integer, Integer) -> Integer -> Integer -> (Integer, Integer)
pow_complex_mod a deg m = pow_complex_mod' a deg m (1, 0)
    where
        pow_complex_mod' :: (Integer, Integer) -> Integer -> Integer -> (Integer, Integer) -> (Integer, Integer)
        pow_complex_mod' a deg m r
            | deg == 0 = r
            | deg `mod` 2 == 1 = pow_complex_mod' (mult_complex_mod a a  m) (deg `div` 2) m (mult_complex_mod r a m)
            | otherwise        = pow_complex_mod' (mult_complex_mod a a  m) (deg `div` 2) m r

main :: IO ()
main = do
    q <- readLn :: IO Int
    forM_ [1..q] $ \_ -> do
        params <- getLine
        let [a, b, k, m] = map (read :: String -> Integer) $ words params
        let r = pow_complex_mod (a, b) k m
        putStrLn $ show (fst r) ++ " " ++ (show (snd r))

