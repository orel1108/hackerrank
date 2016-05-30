module Main where

import Data.List (sort)
import qualified Data.Vector as V

isqrt :: Int -> Int
isqrt = floor . sqrt . fromIntegral

div_generator :: Int -> [Int]
div_generator n = div_generator' n 1 r []
    where
        div_generator' n d r divisors
            | d == r                           = divisors
            | d /= n `div` d && n `mod` d == 0 = div_generator' n (d + 1) r ((n `div` d) : divisors ++ [d])
            | n `mod` d == 0                   = div_generator' n (d + 1) r (divisors ++ [d])
            | otherwise                        = div_generator' n (d + 1) r divisors
        r = isqrt n + 1

helper :: (V.Vector Int) -> Int -> Int -> (Int, Int) -> (Int, Int)
helper arr d n (cnt, curr_size)
    | cnt >= n         = (cnt, curr_size)
    | curr_size' == d  = helper arr d n (cnt', 0)
    | curr_size' > d   = (cnt', curr_size')
    | otherwise        = helper arr d n (cnt', curr_size')
    where
        curr_size' = curr_size + arr V.! cnt
        cnt' = cnt + 1

solve :: (V.Vector Int) -> [Int] -> Int -> [Int]
solve arr divisors n = solve' arr divisors n []
    where
        solve' _ [] _ sizes = sizes
        solve' arr (d : divisors) n sizes
            | cnt == n && curr_size == 0 = solve' arr divisors n (d : sizes)
            | otherwise = solve' arr divisors n sizes
            where
                (cnt, curr_size) = helper arr d n (0, 0)

main :: IO ()
main = do
    n <- readLn :: IO Int
    l <- getLine
    let a = map (read :: String -> Int) $ words l
        s = sum a
        d = div_generator s
    putStrLn $ unwords $ map show $ sort $ solve (V.fromList a) d n

