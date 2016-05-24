module Main where

import Control.Monad (forM_)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        d <- getLine
        let [px, py, qx, qy] = map (read :: String -> Int) $ words d
            rx = 2 * qx - px
            ry = 2 * qy - py
        putStrLn $ (show rx) ++ " " ++ (show ry)

