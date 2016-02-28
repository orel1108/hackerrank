f :: Int -> [Int] -> [Int]
f n [] = []
f n (x:arr) = if x < n then x:(f n arr) else f n arr

main = do 
    n <- readLn :: IO Int 
    inputdata <- getContents 
    let 
        numbers = map read (lines inputdata) :: [Int] 
    putStrLn . unlines $ (map show . f n) numbers

