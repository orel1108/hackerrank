module Main where

import Control.Monad (replicateM)

f s = map (read :: String -> Int) $ words s

dist [x1, y1] [x2, y2] = sqrt $ fromIntegral ((x1 - x2) ^ 2 + (y1 - y2) ^ 2)

perim [p] start = dist p start
perim (p1 : p2 : rest) start = dist p1 p2 + perim (p2 : rest) start

main = do
    n <- readLn :: IO Int
    p <- replicateM n getLine
    let points = map f p
    print $ perim points (head points)

