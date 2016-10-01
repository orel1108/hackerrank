module Main where

import Data.List

sortDesc :: [Int] -> [Int]
sortDesc = sortBy (flip compare)

findTriangle triangles
    | length triangles < 3 = []
    | a < b + c            = [c, b, a]
    | otherwise            = findTriangle (tail triangles)
    where
        [a, b, c] = take 3 triangles

main :: IO ()
main = do
    n  <- readLn :: IO Int
    l' <- getLine
    let l = sortDesc $ map (read :: String -> Int) $ words l'
        res = findTriangle l
    if null res
        then print (-1)
        else putStrLn $ unwords $ map show res

