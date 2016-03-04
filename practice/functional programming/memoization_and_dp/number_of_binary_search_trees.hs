import Control.Monad (forM_)

count 0 = 1
count 1 = 1
count n = (sum [count (n - k) * count (k - 1) | k <- [1,2..n]]) `mod` 100000007

fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1)

count' :: Integer -> Integer
count' n = (fact (2 * n)) `div` ((fact n) * (fact (n + 1)))

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Integer
        print $ (count' n) `mod` 100000007

