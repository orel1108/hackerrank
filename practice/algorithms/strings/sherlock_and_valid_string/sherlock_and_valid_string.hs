import Control.Monad (forM_)
import qualified Data.Map as Map
import Data.Maybe
import Data.List
import qualified Data.Set as Set

addKey :: Char -> (Map.Map Char Int) -> (Map.Map Char Int)
addKey k m = Map.insertWith (+) k 1 m

counter :: String -> (Map.Map Char Int)
counter s = foldl (\acc x -> addKey x acc) Map.empty s

sortedFreq :: (Map.Map Char Int) -> [Int]
sortedFreq c = sort $ Map.foldr (\x acc -> x : acc) [] c

solve :: [Int] -> (Set.Set Int) -> String
solve f d
    | Set.size d == 1                    = "YES"
    | Set.size d  > 2                    = "NO"
    | f !! (n - 1) - (f !! (n - 2)) == 1 = "YES"
    | f !! 0 == 1 && f !! 1 > 1          = "YES"
    | otherwise                          = "NO" where
        n = length f

main = do
    s <- getLine
    let c = counter s
        f = sortedFreq c
        d = Set.fromList f
    putStrLn $ solve f d
