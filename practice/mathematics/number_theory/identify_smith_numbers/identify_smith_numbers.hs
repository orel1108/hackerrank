module Main where

sum_digits :: Int -> Int
sum_digits v
    | v == 0 = 0
    | otherwise = r + (sum_digits q)
    where
        (q, r) = divMod v 10

minus :: [Int] -> [Int] -> [Int]
minus (x:xs) (y:ys) = case (compare x y) of 
           LT -> x : minus  xs  (y:ys)
           EQ ->     minus  xs     ys 
           GT ->     minus (x:xs)  ys
minus  xs     _     = xs

primes :: Int -> [Int]
primes n = 2 : sieve [3,5..n]
    where
        sieve (p:xs) 
            | p * p > n = p : xs
            | otherwise = p : sieve (xs `minus` [p * p, p * p + 2 * p..])

solve :: Int -> [Int] -> Int -> Int -> Int
solve _ [] _ s = s
solve n (p:ps) d s
    | n < p          = s
    | n `mod` p == 0 = solve n' ps d s'
    | s > d          = s
    | otherwise      = solve n ps d s
    where
        t = sum_digits p
        solve' n s p t
            | n `mod` p == 0 = solve' nn ns p t
            | otherwise      = (n, s)
            where
                nn = n `div` p
                ns = s + t
        (n', s') = solve' n s p t

main :: IO ()
main = do
    n <- readLn :: IO Int
    let ps = primes 1000000
        d  = sum_digits n
        s  = solve n ps d 0
    if s == d
        then print 1
        else print 0
