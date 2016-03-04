import Control.Monad (forM_)

factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n - 1)

count :: Integer -> Integer -> Integer
count n k = (factorial n `div` (factorial k * factorial(n - k))) `mod` 100000007

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        nk <- getLine
        let params = map (read :: String -> Integer) $ words nk
            n = params !! 0
            k = params !! 1
        print $ count n k

