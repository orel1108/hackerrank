import Control.Applicative
import Control.Monad
import System.IO
import Data.List

numTopics ([], []) = 0
numTopics ((x:team1), (y:team2))
    | x == '1' || y == '1' = 1 + numTopics (team1, team2)
    | otherwise            = numTopics (team1, team2)
    
pairwiseTopics topics n = map (numTopics) [(topics !! i, topics !! j) | i <- [0..(n - 1)], j <- [(i + 1)..(n - 1)]]

decOrder arr = sortBy (\x y -> y `compare` x) arr

main :: IO ()
main = do
    n_temp <- getLine
    let n_t = words n_temp
    let n = read $ n_t!!0 :: Int
    let m = read $ n_t!!1 :: Int
    topics_t <- getContents
    let topics = lines topics_t
        pair_topic = decOrder $ pairwiseTopics topics n
        h = head pair_topic
        res = filter (== h) pair_topic
    print h
    print $ length res
