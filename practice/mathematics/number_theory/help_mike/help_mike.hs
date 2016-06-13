module Main where

import Control.Monad (forM_)

getValues :: Integer -> Integer -> [Integer]
getValues n k = reverse $ getValues' n k 0 []
    where
        getValues' :: Integer -> Integer -> Integer -> [Integer] -> [Integer]
        getValues' n k c vals
            | c == k = vals
            | otherwise = getValues' n k (c + 1) (((n + c) `div` k) : vals)

count :: Integer -> Integer -> Integer
count n k = res `div` 2
    where
        (d, r') = divMod n k
        r       = if r' > 0 then r' - 1 else r'
        vals    = getValues n k
        res'    = sum vals * d + (sum $ take (fromIntegral r) vals)
        res''   = if k `mod` 2 == 0 then res' - d else res'
        res'''  = if n `mod` k == 0 then res'' - d else res''
        res     = if r > (k `div` 2) then res''' + 2 else res'''

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        nk <- getLine
        let [n, k] = map (read :: String -> Integer) $ words nk
        print $ count n k

