module Main where

solve :: Int -> Int -> Int -> Int -> String
solve x1 v1 x2 v2
    | v1 /= v2  = if d * v >= 0 && d `mod` v == 0 then "YES" else "NO"
    | x1 == x2  = "YES"
    | otherwise = "NO"
    where
        d = x1 - x2
        v = v2 - v1

main :: IO ()
main = do
    xv <- getLine
    let [x1, v1, x2, v2] = map (read :: String -> Int) $ words xv
    putStrLn $ solve x1 v1 x2 v2

