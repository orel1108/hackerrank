module Main where
import Control.Monad (forM_)
import qualified Data.Set as Set
import Data.List

generateNewValue :: Int -> Int -> Set.Set Int -> Int
generateNewValue pos k used
    | d > 0 && Set.member d used == False = d
    | otherwise                           = pos + k
    where
        d = pos - k

solve :: Int -> Int -> ([Int], Set.Set Int)
solve n k = foldr (\pos acc -> process pos k acc) ([], Set.empty) [n,n-1..1]
    where
        process pos k res = (value : (fst res), Set.insert value (snd res))
            where value = generateNewValue pos k (snd res)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_  -> do
        params <- getLine
        let [n, k] = map read $ words params :: [Int]
            res_p  = reverse $ fst $ solve n k
        if sort res_p == [1..n]
            then putStrLn $ unwords $ map show res_p
            else print (-1)

