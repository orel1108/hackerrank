module Main where

import qualified Data.Map as M
import Control.Monad (forM_)
import Data.Maybe

d8_1 :: [Int]
d8_1 = [0, 8]

d8_2 :: [Int]
d8_2 = [16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 69, 27, 46, 65, 84, 23, 42, 61]

div_8 :: [M.Map Char Int]
div_8 = [counter $ show v | v <- [104, 112..992]]

addKey :: Char -> M.Map Char Int -> M.Map Char Int
addKey k m = M.insertWith (+) k 1 m

counter :: String -> M.Map Char Int
counter s = foldl (\acc k -> addKey k acc) M.empty s

contains :: M.Map Char Int -> M.Map Char Int -> Bool
contains c1 c2 = M.foldrWithKey (\k v r -> check k v c2 && r) True c1
    where
        check :: Char -> Int -> M.Map Char Int -> Bool
        check k v c
            | f == Nothing || v > v' = False
            | otherwise              = True
            where
                f  = M.lookup k c
                v' = fromJust f

solve :: String -> String
solve s
    | length s == 1 = if elem (read s :: Int) d8_1 then "YES" else "NO"
    | length s == 2 = if elem (read s :: Int) d8_2 then "YES" else "NO"
    | otherwise     = solve' s
    where
        solve' :: String -> String
        solve' s = if ans then "YES" else "NO"
            where
                c = counter s
                ans = foldr (\c' acc -> contains c' c || acc) False div_8

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        putStrLn $ solve s

