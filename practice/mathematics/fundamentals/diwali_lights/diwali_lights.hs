module Main where

pow_mod :: Integer -> Integer -> Integer -> Integer -> Integer
pow_mod a 0 m res = res
pow_mod a deg m res
    | deg `mod` 2 == 1 = pow_mod (a * a `mod` m) (deg `div` 2) m (res * a `mod` m)
    | otherwise        = pow_mod (a * a `mod` m) (deg `div` 2) m res

solve :: Integer -> Integer
solve n = pow_mod 2 n 100000 1 - 1

main :: IO ()
main = do
    t <- readLn :: IO Int
    d <- getContents
    putStr $ unlines $ map (show . solve . (read :: String -> Integer)) $ lines d

