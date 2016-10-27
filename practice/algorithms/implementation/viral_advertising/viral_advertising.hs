module Main where

solve :: Int -> Int
solve n = solve' n [2]
    where
        solve' k arr
            | k > 1     = solve' (k - 1) (x : arr)
            | otherwise = sum arr
            where
                x = (head arr * 3) `div` 2

main :: IO ()
main = do
    n <- readLn :: IO Int
    print $ solve n

