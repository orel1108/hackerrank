import Data.List

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted a = and $ zipWith (<=) a (tail a)

findBegin :: [Int] -> Int
findBegin [] = 0
findBegin [x] = 0
findBegin (x:y:a)
    | x <= y = 1 + findBegin (y:a)
    | otherwise = 0

findEnd :: [Int] -> Int
findEnd a = length a - 1 - findEnd' (reverse a) where
    findEnd' [] = 0
    findEnd' [x] = 0
    findEnd' (x:y:a)
        | x >= y = 1 + findEnd' (y:a)
        | otherwise = 0

swapElementsAt :: Int -> Int -> [Int] -> [Int]
swapElementsAt a b list = list1 ++ [list !! b] ++ list2 ++ [list !! a] ++ list3
    where   list1 = take a list
            list2 = drop (succ a) (take b list)
            list3 = drop (succ b) list
            
reverseSegment a b list = list1 ++ list2 ++ list3
    where   list1 = take a list
            list2 = reverse $ take (b - a + 1) (drop a list)
            list3 = drop (succ b) list

isAlmostSorted a
    | isSorted a = "yes"
    | isSorted s = "yes\nswap " ++ (show (begin + 1)) ++ " " ++ (show (end + 1))
    | isSorted t = "yes\nreverse " ++ (show (begin + 1)) ++ " " ++ (show (end + 1))
    | otherwise  = "no" where
        begin = findBegin a
        end   = findEnd a
        s = swapElementsAt begin end a
        t = reverseSegment begin end a
        
main = do
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
    putStrLn $ isAlmostSorted a
