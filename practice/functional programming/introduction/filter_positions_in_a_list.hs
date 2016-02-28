f :: [Int] -> [Int]
f lst = [lst !! k | k <- [1,3..length lst]]

main = do
   inputdata <- getContents
   mapM_ (putStrLn. show). f. map read. lines $ inputdata

