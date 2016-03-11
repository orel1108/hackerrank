import Control.Monad (forM_)

cntDivs x d = do
    if x < d
        then if d `mod` x == 0
            then 1 + cntDivs (x + 1) d
            else cntDivs (x + 1) d
        else 1

commonDivs n m = cntDivs 1 d where
    d = gcd n m

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        nm <- getLine
        let p = map (read :: String -> Int) $ words nm
            n = p !! 0
            m = p !! 1
            r = commonDivs n m
        putStrLn $ show r

