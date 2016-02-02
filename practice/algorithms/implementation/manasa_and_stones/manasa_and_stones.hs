import Control.Monad (forM_)

findValues n a b
    | n == 1 = [0]
    | a == b = [a * (n - 1)]
    | otherwise = [a' * (n - j) + b' * (j - 1) | j <- [1..n]] where
        [a', b'] = if a < b
                        then [a, b]
                        else [b, a]

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        a <- readLn :: IO Int
        b <- readLn :: IO Int
        putStrLn $ unwords $ map show $ findValues n a b
