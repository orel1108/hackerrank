module Main where

import Control.Monad (forM_)

small_primes :: [Integer]
small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

pow_mod :: Integer -> Integer -> Integer -> Integer
pow_mod a d m = pow_mod' a d m 1
    where
        pow_mod' :: Integer -> Integer -> Integer -> Integer -> Integer
        pow_mod' a d m r
            | d == 0         = r
            | d `mod` 2 == 1 = pow_mod' (a * a `mod` m) (d `div` 2) m (r * a `mod` m)
            | otherwise      = pow_mod' (a * a `mod` m) (d `div` 2) m r
            
inverse_mod :: Integer -> Integer -> Integer
inverse_mod a p = pow_mod a (p - 2) p

decompose :: Integer -> Integer -> [Integer]
decompose v p = decompose' v p []
    where decompose' v p coeffs
            | v == 0    = reverse coeffs
            | otherwise = decompose' v' p coeffs'
            where
                v'      = v `div` p
                x       = v `mod` p
                coeffs' = x : coeffs

binom_mod :: Integer -> Integer -> Integer -> Integer
binom_mod n m p
    | n < m     = 0
    | m == 0    = 1
    | n == m    = 1
    | otherwise = binom_mod' n m p 1 1 0
    where
        binom_mod' n m p num den cnt
            | cnt == n - m = (num `div` den) `mod` p
            | otherwise    = binom_mod' n m p num' den' cnt'
            where
                num' = num * (n - cnt)
                den' = den * (n - m - cnt)
                cnt' = cnt + 1

lucas :: Integer -> Integer -> Integer -> Integer
lucas n m p = foldr (\v r -> v * r `mod` p) 1 coeffs
    where
        n_coeffs  = decompose n p
        m_coeffs' = decompose m p
        diff      = length n_coeffs - (length m_coeffs')
        m_coeffs  = if diff > 0 then (m_coeffs' ++ [0 | k <- [1..diff]]) else m_coeffs'
        coeffs    = zipWith (\cn cm -> binom_mod cn cm p) n_coeffs m_coeffs

crt :: [Integer] -> [Integer] -> Integer
crt a plist = sum z `mod` n
    where
        n = foldr (*) 1 plist
        d = map (\p -> n `div` p) plist
        s = map (\p -> inverse_mod (n `div` p) p) plist
        z = zipWith3 (\u v w -> u * v * w) a d s

solve :: Integer -> Integer -> Integer -> [Integer] -> Integer
solve n r m plist = crt a p
    where
        [a, p] = foldr (\pr acc -> if m `mod` pr == 0 then [(lucas n r pr) : (acc !! 0), pr : (acc !! 1)] else acc) [[], []] plist

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        i <- getLine
        let [n, r, m] = map (read :: String -> Integer) $ words i
        print $ solve n r m small_primes

