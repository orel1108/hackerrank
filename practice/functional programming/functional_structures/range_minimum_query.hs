import Control.Monad (forM_)
import Data.Vector as V (Vector, fromList, length, (!), splitAt, tail)

data STree a = Node {
    value :: a,
    lRange :: a,
    rRange :: a,
    leftNode :: STree a,
    rightNode :: STree a
} | Empty

getValue :: STree Int -> Int
getValue Empty = maxBound :: Int
getValue node = value node

buildSTree :: V.Vector Int -> STree Int
buildSTree arr = rangeSTreeUtil arr 0 (V.length arr - 1)

rangeSTreeUtil :: V.Vector Int -> Int -> Int -> STree Int
rangeSTreeUtil arr l r = do
    if l > r 
        then Empty
        else if l == r 
                then Node (arr V.! l) l r Empty Empty
                else Node val l r lNode rNode
    where mid = quot (l + r) 2
          lNode = rangeSTreeUtil arr l mid
          rNode = rangeSTreeUtil arr (mid + 1) r
          val = min (getValue lNode) (getValue rNode)

rmq :: STree Int -> Int -> Int -> Int
rmq Empty _ _ = maxBound :: Int
rmq node l r = do
    if (r < ll) || (rr < l) 
        then maxBound :: Int
        else if (l <= ll) && (rr <= r) 
            then getValue node
            else min (rmq (leftNode node) l r) (rmq (rightNode node) l r)
    where ll = lRange node
          rr = rRange node

main = do
    params <- getLine
    sa <- getLine
    s <- getContents
    let arr = map (read :: String -> Int) $ words sa
        queries = map (map (read :: String -> Int) . words) $ lines s
        vec = V.fromList arr
        tree = buildSTree vec
        res = map (\[l,r] -> rmq tree l r) queries
    putStr $ unlines $ map show res

