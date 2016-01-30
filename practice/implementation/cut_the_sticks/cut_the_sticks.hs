import Control.Applicative
import Control.Monad
import System.IO
import Data.List

numToCut [] = []
numToCut arr = n : numToCut arr' where
    s = head arr
    similar = filter (==s) arr
    n = length similar
    arr' = drop n arr
    
partSums arr = 0 : scanl1 (+) arr

solve arr n = map (\x -> n - x) $ init arr

main :: IO ()
main = do
    n <- readLn :: IO Int
    arr_temp <- getLine
    let arr = sort $ map read $ words arr_temp :: [Int]
    putStr $ unlines $ map show $ solve (partSums $ numToCut arr) n
    
