module Main where

minus :: [Integer] -> [Integer] -> [Integer]
minus (x:xs) (y:ys) = case (compare x y) of 
           LT -> x : minus  xs  (y:ys)
           EQ ->     minus  xs     ys 
           GT ->     minus (x:xs)  ys
minus  xs     _     = xs

primes :: Integer -> [Integer]
primes n = 2 : sieve [3,5..n]
    where
        sieve (p:xs) 
            | p * p > n = p : xs
            | otherwise = p : sieve (xs `minus` [p * p, p * p + 2 * p..])

solve :: Integer -> [Integer] -> Integer -> Integer
solve _ [] r = r
solve n (p:ps) r = solve n ps r'
    where
        solve' n pd p s
            | n `div` pd > 0 = solve' n (pd * p) p ((s + n `div` pd) `mod` 1000007)
            | otherwise      = s
        s  = solve' n p p 0
        r' = r * (2 * s + 1) `mod` 1000007

main :: IO ()
main = do
    n <- readLn :: IO Integer
    let ps = primes 1000000
    print $ solve n ps 1

