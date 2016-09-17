module Main where

main :: IO ()
main = do
    nk <- getLine
    c' <- getLine
    b  <- readLn :: IO Int
    let [n, k] = map (read :: String -> Int) $ words nk
        c      = map (read :: String -> Int) $ words c'
        total  = sum $ (take k c) ++ (drop (k + 1) c)
        half   = total `div` 2
    if b > half
        then print $ b - half
        else putStrLn "Bon Appetit"

