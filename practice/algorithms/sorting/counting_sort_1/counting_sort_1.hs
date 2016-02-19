import qualified Data.Map as Map

fillMap = foldl (\acc x -> Map.insert x 0 acc) Map.empty [0..99]

addKey k m = Map.insertWith (+) k 1 m

counter a = foldl (\acc x -> addKey x acc) fillMap a

main = do
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
    putStr $ unwords $ map (show . snd) (Map.toList $ counter a)
