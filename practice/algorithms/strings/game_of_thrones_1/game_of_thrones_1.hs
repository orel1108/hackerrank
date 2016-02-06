import qualified Data.Map as Map

addKey m key = Map.insertWith (+) key 1 m

frequency s = foldl (\acc x -> addKey acc x) Map.empty s

main = do
    s <- getLine
    let n = filter (\x -> snd x `mod` 2 == 1) (Map.toList $ frequency s)
    if length n > 1
        then putStrLn "NO"
        else putStrLn "YES"
