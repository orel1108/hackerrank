module Main where

import Control.Monad (forM_)
import Text.Printf

main :: IO ()
main = do
    c <- getLine
    let [l, s1, s2] = map (read :: String -> Double) $ words c
        s = sqrt(2.0) * l
        t = abs $ s1 - s2
    q <- readLn :: IO Int
    forM_ [1..q] $ \_ -> do
        qi <- readLn :: IO Double
        let r = sqrt(2.0 * qi)
            ans = (abs (r - s)) / t
        printf "%.6f\n" ans

