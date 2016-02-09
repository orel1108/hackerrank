import Control.Monad (forM_)
import qualified Data.Map as Map
import Data.Maybe
import Data.List

addKey :: String -> (Map.Map String Int) -> (Map.Map String Int)
addKey k m = Map.insertWith (+) k 1 m

counter :: [String] -> (Map.Map String Int)
counter s = foldl (\acc x -> addKey (sort x) acc) Map.empty s

subStrings s l = [take m (drop n s) | n <- [0..l], m <- [1..l], n + m <= l]

numPairs c = Map.foldl (\acc x -> acc + (x * (x - 1) `div` 2)) 0 c

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        let ss = subStrings s (length s)
            c = counter ss
        print $ numPairs c
