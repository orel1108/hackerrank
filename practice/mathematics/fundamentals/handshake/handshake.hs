module Main where

solve :: Int -> Int
solve n = n * (n - 1) `div` 2

main :: IO ()
main = do
    t <- readLn :: IO Int
    d <- getContents
    let r = map (show . solve . (read :: String -> Int)) $ lines d
    putStr $ unlines r

