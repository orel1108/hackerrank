solve :: [Int] -> [Double]
solve arr = [pos, neg, zero] where
    pos = fromIntegral . length $ filter (>0) arr
    neg = fromIntegral . length $ filter (<0) arr
    zero = fromIntegral . length $ filter (==0) arr


main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Double
    arr_temp <- getLine
    let arr = map read $ words arr_temp :: [Int]
        ans = solve arr
    print $ ans !! 0 / n
    print $ ans !! 1 / n
    print $ ans !! 2 / n
