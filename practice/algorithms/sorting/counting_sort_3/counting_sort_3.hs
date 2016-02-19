import qualified Data.Map as Map

fillMap = foldl (\acc x -> Map.insert x 0 acc) Map.empty [0..99]

addKey k m = Map.insertWith (+) k 1 m

counter a = foldl (\acc x -> addKey x acc) fillMap a

solve c = scanl1 (\acc x -> acc + x) c

main = do
    n <- readLn :: IO Int
    ar <- getContents
    let a = map (read :: String -> Int) $ map (!! 0) $ map words $ lines ar
        c = counter a
        l = solve $ map snd $ Map.toList c
    putStrLn $ unwords $ map show l
