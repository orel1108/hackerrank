import qualified Data.Matrix as Matrix
import qualified Data.Map as Map
import Data.Maybe

insertVal s1 s2 row col m = Map.insert (row, col) v m where
    v = if s1 !! (row - 1) == (s2 !! (col - 1))
            then fromJust (Map.lookup (row - 1, col - 1) m) + 1
            else max (fromJust $ Map.lookup (row, col - 1) m) (fromJust $ Map.lookup (row - 1, col) m)

initMap n = Map.fromList ([((row, 0), 0) | row <- [0..n]] ++ [((0, col), 0) | col <- [0..n]])

constructTable s1 s2 n = foldl (\acc (row, col) -> insertVal s1 s2 row col acc) (initMap n) [(row, col) | row <- [1..n], col <- [1..n]]

main = do
    s1 <- getLine
    s2 <- getLine
    let n = length s1
        table = constructTable s1 s2 n
    print $ fromJust (Map.lookup (n, n) table)
