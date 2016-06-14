module Main where

import Control.Monad (forM_)

pairLcm :: [Int] -> [Int]
pairLcm arr = zipWith lcm arr (tail arr)

solve :: [Int] -> [Int]
solve arr = (head arr) : (pairLcm arr) ++ [last arr]

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n  <- readLn :: IO Int
        a' <- getLine
        let a = map (read :: String -> Int) $ words a'
        putStrLn $ unwords $ map show $ solve a

