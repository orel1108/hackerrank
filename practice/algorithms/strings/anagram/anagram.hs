import Control.Monad (forM_)
import qualified Data.Map as Map
import Data.Maybe

addKey :: Char -> (Map.Map Char Int) -> (Map.Map Char Int)
addKey k m = Map.insertWith (+) k 1 m

counter :: String -> (Map.Map Char Int)
counter s = foldl (\acc x -> addKey x acc) Map.empty s

valueDiff :: (Char, Int) -> (Map.Map Char Int) -> Int
valueDiff (k, v) c = do
    if x == Nothing
        then v
        else (v - fromJust x) where
            x = Map.lookup k c

counterDiff :: (Map.Map Char Int) -> (Map.Map Char Int) -> [Int]
counterDiff c1 c2 = Map.foldlWithKey (\acc k v -> acc ++ [valueDiff (k, v) c2]) [] c1

posAndNeg :: [Int] -> (Int, Int)
posAndNeg d = (sum $ filter (<0) d, sum $ filter (>0) d)

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        let n = length s
        if n `mod` 2 == 1
            then putStrLn "-1"
            else do
                let h = n `div` 2
                    c1 = counter $ take h s
                    c2 = counter $ drop h s
                    diff = counterDiff c1 c2
                    pn = posAndNeg diff
                print $ max (fst pn) (abs $ snd pn)

