module Main where

import qualified Data.Map as M

to_tuple :: [String] -> (String, String)
to_tuple [a, b] = (a, b)

parse :: [String] -> [[(String, String)]]
parse [] = []
parse cases = map to_tuple (map words (take n r)) : parse (drop n r)
    where
        n = read (head cases) :: Int
        r = tail cases

is_function :: [(String, String)] -> Bool
is_function c = (length c) == (length $ M.keys (M.fromListWith (++) c))

solve :: [[(String, String)]] -> [String]
solve [] = []
solve (c:cases) = (if is_function c then "YES" else "NO") : solve cases

main :: IO ()
main = do
    t <- readLn :: IO Int
    c <- getContents
    let cases = lines c
    putStrLn $ unlines $ solve $ parse cases

