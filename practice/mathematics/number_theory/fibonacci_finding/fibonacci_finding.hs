module Main where

import qualified Data.Matrix as M

m :: Integer
m = 1000000007

matrix_pow :: M.Matrix Integer -> Integer -> M.Matrix Integer
matrix_pow a n
    | n == 0 = M.identity 2
    | n == 1 = a
    | otherwise = matrix_pow' a n (M.fromLists [[1, 0], [0, 1]])
    where
        matrix_pow' a n r
            | n == 0         = r
            | n `mod` 2 == 1 = matrix_pow' a' (n `div` 2) r'
            | otherwise      = matrix_pow' a' (n `div` 2) r
            where
                r11 = (((M.getElem 1 1 r) * (M.getElem 1 1 a)) + ((M.getElem 1 2 r) * (M.getElem 2 1 a))) `mod` m
                r12 = (((M.getElem 1 1 r) * (M.getElem 1 2 a)) + ((M.getElem 1 2 r) * (M.getElem 2 2 a))) `mod` m
                r21 = (((M.getElem 2 1 r) * (M.getElem 1 1 a)) + ((M.getElem 2 2 r) * (M.getElem 2 1 a))) `mod` m
                r22 = (((M.getElem 2 1 r) * (M.getElem 1 2 a)) + ((M.getElem 2 2 r) * (M.getElem 2 2 a))) `mod` m
                r'  = M.fromLists [[r11, r12], [r21, r22]]
                
                a11 = (((M.getElem 1 1 a) * (M.getElem 1 1 a)) + ((M.getElem 1 2 a) * (M.getElem 2 1 a))) `mod` m
                a12 = (((M.getElem 1 1 a) * (M.getElem 1 2 a)) + ((M.getElem 1 2 a) * (M.getElem 2 2 a))) `mod` m
                a21 = (((M.getElem 2 1 a) * (M.getElem 1 1 a)) + ((M.getElem 2 2 a) * (M.getElem 2 1 a))) `mod` m
                a22 = (((M.getElem 2 1 a) * (M.getElem 1 2 a)) + ((M.getElem 2 2 a) * (M.getElem 2 2 a))) `mod` m
                a'  = M.fromLists [[a11, a12], [a21, a22]]

fib :: [Integer] -> Integer
fib [a, b, n] = (((M.getElem 2 1 mat) * b) + ((M.getElem 2 2 mat) * a)) `mod` m
    where
        mat = matrix_pow (M.fromLists [[1, 1], [1, 0]]) n

main :: IO ()
main = do
    t <- readLn :: IO Int
    c <- getContents
    let d = map ((map (read :: String -> Integer)) . words) $ lines c
    putStr $ unlines $ map (show . fib) d

