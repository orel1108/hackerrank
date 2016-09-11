module Main where

solve :: [Int] -> Int -> Int
solve [x] res
    | x `mod` 2 == 0 = res
    | otherwise      = (-1)
solve b res
    | head b `mod` 2 == 1 = solve ((head other + 1) : (tail other)) (res + 2)
    | otherwise           = solve other res
    where
        other = tail b


main :: IO ()
main = do
    n  <- readLn :: IO Int
    b' <- getLine
    let b = map (read :: String -> Int) $ words b'
        res = solve b 0
    if res >= 0
        then print res
        else putStrLn "NO"

