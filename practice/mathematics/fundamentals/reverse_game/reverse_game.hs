module Main where

import Data.List
import Data.Maybe
import Control.Monad (forM_)

solve n k = elemIndex k $ reverse $ n `div` 2 : foldl (\acc x -> x : (n - x - 1) : acc) [] [0..(n `div` 2 - 1)]

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        d <- getLine
        let [n, k] = map (read :: String -> Int) $ words d
        print $ fromJust $ solve n k

