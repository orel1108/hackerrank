module Main where

main :: IO ()
main = do
    nd <- getLine
    a' <- getLine
    let [n, d] = map (read :: String -> Int) $ words nd
        a      = map (read :: String -> Int) $ words a'
        m      = d `mod` n
        r      = drop m a ++ (take m a)
    putStrLn $ unwords $ map show r

