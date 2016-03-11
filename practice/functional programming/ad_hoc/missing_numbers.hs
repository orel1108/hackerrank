import qualified Data.Set as Set
import Data.List

findDiff [] b = nub $ sort b
findDiff (a:arr) b = findDiff arr b' where
    b' = delete a b

main = do
    n <- readLn :: IO Int
    sa <- getLine
    m <- readLn :: IO Int
    sb <- getLine
    let a = map (read :: String -> Int) $ words sa
        b = map (read :: String -> Int) $ words sb
        d = findDiff a b
    putStr . unwords $ map show d

