import qualified Data.Map as Map

addKey k m = Map.insertWith (+) k 1 m

counter a = foldl (\acc x -> addKey x acc) Map.empty a

countSort c = foldl (\acc x -> acc ++ (replicate (snd x) (fst x))) [] c

main = do
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
        c = Map.toList $ counter a
    putStrLn $ unwords $ map show (countSort c)
