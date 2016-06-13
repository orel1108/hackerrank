module Main where

import qualified Data.Vector as V
import Control.Monad (forM_)

maxN :: Int
maxN = 10000

updateIsPrimes :: Int -> Int -> V.Vector Bool -> V.Vector Bool
updateIsPrimes i n is_prime = V.update is_prime (V.fromList [(j, False) | j <- [i * i, i * (i + 1)..n]])

sieveUtil :: Int -> Int -> V.Vector Bool -> V.Vector Bool
sieveUtil i n is_prime
    | i * i > n      = is_prime
    | is_prime V.! i = sieveUtil (i + 1) n (updateIsPrimes i n is_prime)
    | otherwise      = sieveUtil (i + 1) n is_prime

sieve :: Int -> V.Vector Bool
sieve n = sieveUtil 2 n (V.fromList (False : False : [True | k <- [2..n]]))

primeList :: V.Vector Bool -> V.Vector Int
primeList is_prime = V.findIndices (==True) is_prime

findDegree :: Int -> Int -> (Int, Int)
findDegree n p = findDegree' n p 0
    where findDegree' n p deg
            | n `mod` p /= 0 = (n, deg)
            | otherwise      = findDegree' (n `div` p) p (deg + 1)

phiUtil :: Int -> [Int] -> V.Vector Int -> Int
phiUtil n (p : primes) phi_vals
    | n `mod` p /= 0 = phiUtil n primes phi_vals
    | otherwise      = p ^ (deg - 1) * (p - 1) * (phi_vals V.! m)
    where
        (m, deg) = findDegree n p

phi :: Int -> [Int] -> V.Vector Int
phi n primes = phi' 2 n (V.fromList [0, 1]) primes
    where
        phi' v n phi_vals primes
            | v > n     = phi_vals
            | otherwise = phi' (v + 1) n (V.snoc phi_vals k) primes
            where
                k = phiUtil v primes phi_vals

pow_mod_util :: Int -> Int -> Int -> Int -> Int
pow_mod_util a 0 m res = res
pow_mod_util a deg m res
    | deg `mod` 2 == 1 = pow_mod_util (a * a `mod` m) (deg `div` 2) m (res * a `mod` m)
    | otherwise        = pow_mod_util (a * a `mod` m) (deg `div` 2) m res

pow_mod :: Int -> Int -> Int -> Int
pow_mod a d p = pow_mod_util a d p 1

solve :: [Int] -> V.Vector Int -> Int
solve [a, b, x] phi_vals
    | b >= 0    = pow_mod a b x
    | otherwise = pow_mod y (abs b) x
    where
        y = pow_mod a (phi_vals V.! x - 1) x

main :: IO ()
main = do
    t <- readLn :: IO Int
    let is_prime = sieve maxN
        primes   = primeList is_prime
        phi_vals = phi maxN (V.toList primes)
    forM_ [1..t] $ \_ -> do
        c <- getLine
        let [a, b, x] = map (read :: String -> Int) $ words c
        print $ solve [a, b, x] phi_vals

