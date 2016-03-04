import Control.Monad (forM_)

pentagonal n = n * (3 * n - 1) `div` 2

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        print $ pentagonal n

