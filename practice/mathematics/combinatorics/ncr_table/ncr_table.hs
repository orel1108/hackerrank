module Main where

import Control.Monad (forM_)

pascal_row :: [Int] -> [Int]
pascal_row prev = 1 : [(x + y) `mod` 1000000000 | (x, y) <- zip prev (tail prev)] ++ [1]

pascalUtil :: Int -> [[Int]] -> [[Int]]
pascalUtil n tr
    | n < 1000  = pascalUtil (n + 1) ((pascal_row (head tr)) : tr)
    | otherwise = tr
    
pascal :: [[Int]]
pascal = reverse $ pascalUtil 0 [[1, 1], [1]]

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        putStrLn $ unwords $ map show $ pascal !! n

