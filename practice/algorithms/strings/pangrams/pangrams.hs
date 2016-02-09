import qualified Data.Set as Set
import Data.Char

main = do
    w <- getLine
    let s = Set.fromList $ map toLower (concat $ words w)
    if Set.size s == 26
        then putStrLn "pangram"
        else putStrLn "not pangram"

