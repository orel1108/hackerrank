module Main where

main :: IO ()
main = do
    a <- getLine
    let v = map (read :: String -> Integer) $ words a
        min_s = (sum v) - (maximum v)
        max_s = (sum v) - (minimum v)
    putStrLn $ show min_s ++ " " ++ (show max_s)

