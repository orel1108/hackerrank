import Control.Monad (forM_)
import Data.List
import qualified Data.Set as Set
import qualified Data.Maybe as Maybe

revSort arr = sortBy (\a b -> compare b a) arr

partSums arr = scanl1 (+) arr

solve p s = Set.lookupGE s p

main = do
    n <- readLn :: IO Int
    sa <- getLine
    let a = revSort $ map (read :: String -> Int) $ words sa
        p = Set.fromList $ partSums a
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- readLn :: IO Int
        let r = solve p s
        if r == Nothing
            then putStrLn "-1"
            else print $ (Set.findIndex (Maybe.fromJust r) p) + 1

