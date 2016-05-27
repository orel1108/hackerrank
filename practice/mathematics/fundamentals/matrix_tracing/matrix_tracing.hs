module Main where

pow_mod :: Integer -> Integer -> Integer -> Integer -> Integer
pow_mod a 0 m res = res
pow_mod a deg m res
    | deg `mod` 2 == 1 = pow_mod (a * a `mod` m) (deg `div` 2) m (res * a `mod` m)
    | otherwise        = pow_mod (a * a `mod` m) (deg `div` 2) m res

fact_mod :: Integer -> Integer -> Integer
fact_mod n m
    | n == 0 = 1
    | n > 0  = (n * (fact_mod (n - 1) m)) `mod` m
    
coef :: Integer -> Integer -> Integer -> Integer
coef n k m = (num * iden) `mod` m
    where
        num = fact_mod (n + k - 2) m
        den = fact_mod (n - 1) m * fact_mod (k - 1) m
        iden = pow_mod den (m - 2) m 1

solve :: [Integer] -> Integer
solve [n, k] = coef n k 1000000007

main :: IO ()
main = do
    t <- readLn :: IO Int
    l <- getContents
    let d = map (map (read :: String -> Integer) . words) $ lines l
    putStr $ unlines $ map (show . solve) d

