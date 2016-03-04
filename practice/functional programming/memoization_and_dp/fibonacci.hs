import Control.Monad (forM_)

fib 0 = [0]
fib 1 = [1, 0]
fib n = f : prev where
    prev = fib (n - 1)
    f = ((prev !! 0) + (prev !! 1)) `mod` 100000007

main = do
    t <- readLn :: IO Int
    let f = fib 10000
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        print $ f !! (10000 - n)

