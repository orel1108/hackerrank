import qualified Data.Set as Set

findGems rockElems = foldr (Set.intersection) (Set.fromList ['a'..'z']) rockElems

main = do
    n <- readLn :: IO Int
    rocks <- getContents
    let rockElems = map Set.fromList $ lines rocks
    print $ Set.size $ findGems rockElems
