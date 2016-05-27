module Main where

solve :: [Integer] -> Integer
solve [x1, y1, x2, y2]
    | x1 == x2 && y1 == y2 = 0
    | x1 == x2             = abs (y1 - y2) - 1
    | y1 == y2             = abs (x1 - x2) - 1
    | otherwise            = solve' [x1, y1, x2, y2]
    where
        solve' [x1, y1, x2, y2] = (x2' - x1' - 1) `div` x
            where
                x1' = min x1 x2
                x2' = max x1 x2
                t1  = abs (x1 - x2)
                t2  = abs (y1 - y2)
                d   = gcd t1 t2
                x   = t1 `div` d

main :: IO ()
main = do
    t <- readLn :: IO Int
    l <- getContents
    let d = map ((map (read :: String -> Integer)) . words) $ lines l
    putStr $ unlines $ map (show . solve) d

