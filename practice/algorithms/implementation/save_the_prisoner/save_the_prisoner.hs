module Main where

import Control.Monad (forM_)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        params <- getLine
        let [n, m, s] = map (read :: String -> Integer) $ words params
            r = (m + s - 1) `mod` n
        print $ if r == 0 then n else r

