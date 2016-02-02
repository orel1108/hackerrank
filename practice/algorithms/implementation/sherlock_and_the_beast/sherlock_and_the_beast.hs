import Control.Applicative
import Control.Monad
import System.IO
import Data.List

findNumber n = findNumber' n 0 where
    findNumber' n k
        | k <= n && ((n - k) `mod` 3 == 0) = replicate (n - k) '5' ++ (replicate k '3')
        | k > n = "-1"
        | otherwise = findNumber' n (k + 5)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_  -> do
        n <- readLn :: IO Int
        putStrLn $ findNumber n
