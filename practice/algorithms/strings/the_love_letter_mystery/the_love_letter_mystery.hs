import Control.Monad (forM_)
import Data.Char

count :: [Char] -> Int
count s = sum [abs $ ord (s !! k) - (ord (s !! (l - k - 1))) | k <- [0..(l `div` 2 - 1)]] where
    l = length s

count' []  = 0
count' [a] = 0
count' s = abs (x - y) + count' s' where
    x = ord $ head s
    y = ord $ last s
    s' = drop 1 $ init s

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        print $ count' s
