module Main where

getData :: String -> [Int]
getData s = map (read :: String -> Int) $ words s

solve :: [Int] -> Int
solve [l, b] = l * b `div` (g * g)
    where
        g = gcd l b

main :: IO ()
main = do
    t <- readLn :: IO Int
    d <- getContents
    let v = map getData $ lines d
        r = map solve v
    putStr $ unlines $ map show r
