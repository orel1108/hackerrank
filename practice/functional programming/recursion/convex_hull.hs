import Text.Printf
import Data.List

cww p1 p2 p3 = (fst p2 - fst p1) * (snd p3 - snd p1) - (snd p2 - snd p1) * (fst p3 - fst p1)

comp :: (Int, Int) -> (Int, Int) -> Ordering
comp p1 p2 = if fst p1 /= fst p2
                then compare (fst p1) (fst p2)
                else compare (snd p1) (snd p2)
                
sortPoints :: [(Int, Int)] -> [(Int, Int)]
sortPoints points = sortBy comp points

traverse :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
traverse xs point = if (n >= 2) && (cww (xs !! (n - 2)) (xs !! (n - 1)) point <= 0)
                                then traverse (init xs) point
                                else xs where
                                    n = length xs

traverseLower [] lower = init lower
traverseLower (x:xs) lower = traverseLower xs (traverse lower x ++ [x])

traverseUpper [] upper = init upper
traverseUpper xs upper = traverseLower (reverse xs) upper

dist :: (Int, Int) -> (Int, Int) -> Double
dist p1 p2 = sqrt (fromIntegral d) where
    d = (fst p1 - fst p2) ^ 2 + (snd p1 - snd p2) ^ 2

solve :: [(Int, Int)] -> Double
solve [x] = 0.0
solve (p1:p2:points) = (dist p1 p2) + solve (p2:points)

main :: IO ()
main = do
  n <- readLn :: IO Int
  content <- getContents
  let  
    points = map (\[x, y] -> (x, y)). map (map (read::String->Int)). map words. lines $ content
    sp = sortPoints points
    lower = traverseLower sp []
    upper = traverseUpper sp []
    ans = solve (lower ++ upper)
    d = dist (head lower) (last upper)
  printf "%.2f\n" (ans + d)

