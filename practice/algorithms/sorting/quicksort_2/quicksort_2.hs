import Data.List

printList arr = putStrLn $ unwords $ map show arr

quickSort :: [Int] -> IO [Int]
quickSort [] = return []
quickSort [x] = return [x]
quickSort (p:arr) = do
    left  <- quickSort $ filter (<p) arr
    right <- quickSort $ filter (>p) arr
    let res = left ++ [p] ++ right
    printList res
    return res

main = do
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
    quickSort a
