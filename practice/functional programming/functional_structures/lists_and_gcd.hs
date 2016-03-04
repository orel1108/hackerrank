import qualified Data.Map as Map
import Data.List

gcdList :: [(Int, Int)] -> [(Int, Int)]
gcdList arr = Map.toList $ foldr (\ele mm -> Map.insertWith (min) (fst ele) (snd ele) mm) Map.empty arr

getPairs [] = []
getPairs (x:y:rest) = (x, y) : getPairs rest

comp (x1, y1) (x2, y2) = do
    if x1 == x2
        then compare y1 y2
        else compare x1 x2

gcdList' arr n = do 
    if length arr < n 
        then []
        else do
            if length farr == n
                then head arr : gcdList' (drop n arr) n
                else gcdList' (drop c arr) n where
                    farr = filter (\(a, b) -> a == a0) (take n arr) where
                        a0 = fst $ head arr
                    c = length farr

toPrint [] = ""
toPrint (x:xs) = show (fst x) ++ " " ++ show (snd x) ++ " " ++ toPrint xs

main = do
    n <- readLn :: IO Int
    s <- getContents
    let factors = map words $ lines s
        ifactors = map (map (read ::String -> Int)) factors
        pairs = map getPairs ifactors
        arr = sortBy comp (foldl (\acc x -> acc ++ x) [] pairs)
    putStrLn $ toPrint $ gcdList' arr n

