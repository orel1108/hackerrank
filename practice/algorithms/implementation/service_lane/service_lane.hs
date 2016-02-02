import Control.Monad (forM_)
minWidth width i j = minimum $ take (j - i + 1) $ drop i width


main :: IO ()
main = do
    n_temp <- getLine
    let n_t = words n_temp
    let n = read $ n_t!!0 :: Int
    let t = read $ n_t!!1 :: Int
    width_temp <- getLine
    let width = map read $ words width_temp :: [Int]
    forM_ [1..t] $ \_  -> do
        i_temp <- getLine
        let i_t = words i_temp
        let i = read $ i_t!!0 :: Int
        let j = read $ i_t!!1 :: Int
        print $ minWidth width i j

