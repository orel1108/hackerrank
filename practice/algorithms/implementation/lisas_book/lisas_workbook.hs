module Main where

util :: Int -> Int -> (Int, Int) -> (Int, Int)
util ti k (res, curr_page) = foldl (\acc t -> util' t ti k acc) (res, curr_page) [pos | pos <- [1..ti]]
    where
        util' :: Int -> Int -> Int -> (Int, Int) -> (Int, Int)
        util' t ti k (res, curr_page) = (res', curr_page')
            where
                res' = if t == curr_page then res + 1 else res
                curr_page' = if t == ti || t `mod` k == 0 then curr_page + 1 else curr_page

solve :: Int -> [Int] -> (Int, Int) -> (Int, Int)
solve k t (res, curr_page) = foldl (\acc ti -> util ti k acc) (res, curr_page) t

main :: IO ()
main = do
    nk <- getLine
    t' <- getLine
    let [n, k] = map (read :: String -> Int) $ words nk
        t = map (read :: String -> Int) $ words t'
    print $ fst $ solve k t (0, 1)

