import Control.Applicative
import Control.Monad
import System.IO

cancelation atime k
    | c < k = "YES"
    | otherwise = "NO" where
        c = length $ filter (<1) atime 

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n_temp <- getLine
        let n_t = words n_temp
        let n = read $ n_t!!0 :: Int
        let k = read $ n_t!!1 :: Int
        a_temp <- getLine
        let a = map read $ words a_temp :: [Int]
        putStrLn $ cancelation a k

