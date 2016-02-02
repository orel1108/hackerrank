main :: IO ()
main = do
    n_temp <- getLine
    arr_temp <- getLine
    let n = read n_temp :: Int
        arr = map read $ words arr_temp :: [Int]     
    print $ sum arr

