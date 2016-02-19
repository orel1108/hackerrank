import Control.Monad
import Data.List

findPos a = length $ dropWhile (> (last a)) (reverse $ init a)

insert a = take n a ++ [last a] ++ (init $ drop n a) where
    n = findPos a

insertSort a p n = do
    if p >= n
        then 0
        else (p - x) + insertSort na (p + 1) n where
            x = findPos (take (p + 1) a)
            na = take x a ++ [a !! p] ++ (delete (a !! p) (drop x a))

main = do
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
    print $ insertSort a 1 n
    
