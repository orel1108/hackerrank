import Control.Applicative
import Control.Monad
import System.IO

digits n
    | n < 10 = [n]
    | otherwise = n `mod` 10 : digits (n `div` 10)
    
solve n = filter (\x -> x > 0 && n `mod` x == 0) (digits n)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_  -> do
        n <- readLn :: IO Int
        print $ length $ solve n

