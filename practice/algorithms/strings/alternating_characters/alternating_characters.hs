import Control.Monad (forM_)

unique [] _ = []
unique (x:s) c
    | x == c = unique s c
    | otherwise = x : unique s x

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        print $ length s - (length $ unique s 'X')
