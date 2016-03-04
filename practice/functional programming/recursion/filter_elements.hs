import qualified Data.List as List
import qualified Data.Map as Map
import Control.Applicative ((<$>))
import Control.Monad (forM_)

solve :: String -> [String] -> String
solve params arr = if null filtered
                then "-1"
                else foldr (\a b -> a ++ " " ++ b) "" filtered
    where iparams = map (\s -> read s :: Int) (List.words params)
          k = iparams !! 1
          m = foldr (\ele mm -> Map.insertWith (+) ele 1 mm) Map.empty arr
          filtered = List.nub $ filter filter' arr
            where filter' ele = case Map.lookup ele m of
                                        Nothing -> False
                                        Just v -> if v >= k then True else False

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        nk <- getLine
        a <- getLine
        putStrLn $ solve nk (List.words a)

