import qualified Data.Map as Map

addKey m k = Map.insertWith (+) k 1 m

counter s = foldl (\acc x -> addKey acc x) Map.empty s

maybeToInt :: Maybe Int -> Int
maybeToInt Nothing = 0
maybeToInt (Just x) = x

removeChar m1 m2 c = abs (x - y) where
    x = maybeToInt $ Map.lookup c m1
    y = maybeToInt $ Map.lookup c m2

main = do
    s1 <- getLine
    s2 <- getLine
    let m1 = counter s1
        m2 = counter s2
    print $ sum [removeChar m1 m2 c | c <- ['a'..'z']]

