import Data.List
import Data.Maybe

main = do
    v <- readLn :: IO Int
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
    print $ fromJust $ elemIndex v a

