module Main where

import Control.Monad (replicateM)

f s = map (read :: String -> Int) $ words s

diff [x1, y1] [x2, y2] = x1 * y2 - x2 * y1

area [p] start = diff p start
area (p1 : p2 : rest) start = diff p1 p2 + area (p2 : rest) start

main = do
    n <- readLn :: IO Int
    p <- replicateM n getLine
    let points = map f p
    print $ abs(fromIntegral $ area points (head points)) / 2

