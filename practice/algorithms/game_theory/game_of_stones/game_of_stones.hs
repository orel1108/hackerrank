module Main where

import Control.Monad (forM_)

check_pos wp = x : wp
    where
        x = not $ (wp !! 1) && (wp !! 2) && (wp !! 4)

win_pos = reverse $ foldr (\pos acc -> check_pos acc) [True, True, True, True, False, False] [6..100]

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        if win_pos !! n
            then putStrLn "First"
            else putStrLn "Second"

