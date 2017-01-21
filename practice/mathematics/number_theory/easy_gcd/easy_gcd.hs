module Main where

arr_gcd :: [Int] -> Int
arr_gcd a = foldl gcd (head a) a

solve :: Int -> Int -> Int
solve g k = solve' g k 2 0
    where
        solve' g k x r
            | x * x > g = r
            | otherwise = solve' g k (x + 1) r'
            where
                r' = if g `mod` x == 0 then maximum [r, k - k `mod` x, k - k `mod` (g `div` x)] else r

main :: IO ()
main = do
    params <- getLine
    let [n, k] = map (read :: String -> Int) $ words params
    a' <- getLine
    let a = map (read :: String -> Int) $ words a'
        g = arr_gcd a
    print $ max (solve g k) (k - k `mod` g)

