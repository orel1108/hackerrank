import Control.Monad (forM_)

firstGreater :: [Int] -> Int -> Int -> Int
firstGreater [] _ pos = pos
firstGreater (x:xs) a pos = if x > a
                                then pos
                                else firstGreater xs a (pos + 1)

check [] = True
check (x:xs) = do
    let pos = firstGreater xs x (-1)
    if pos == length xs
        then False
        else do
            let f = filter (\v -> v <= x) (drop (pos + 1) xs)
            if null f
                then check (take pos xs) && (check (drop (pos + 1) xs))
                else False

isPreoder [] = True
isPreoder (x:xs) = check (x:xs) && isPreoder xs

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        sa <- getLine
        let a = map (read :: String -> Int) (words sa)
            ans = isPreoder a
        if ans
            then putStrLn "YES"
            else putStrLn "NO"

