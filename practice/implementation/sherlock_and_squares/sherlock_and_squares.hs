import Control.Monad (forM_)

count p q = takeWhile (<=q) $ dropWhile (<p) $ map (^2) [1..]

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        let ws = map (read :: String -> Int) $ words s
            p = ws !! 0
            q = ws !! 1
        print $ length $ count p q
