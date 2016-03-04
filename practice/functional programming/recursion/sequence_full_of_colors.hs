import Control.Applicative ((<$>))
import Control.Monad (forM_)

check :: Int -> Int -> Int -> Int -> Bool
check cr cg cy cb = (abs (cr - cg) <= 1) && (abs (cy - cb) <= 1)

solve :: [Char] -> Int -> Int -> Int -> Int -> Bool
solve [] cr cg cy cb = (cr == cg) && (cy == cb)
solve (x:xs) cr cg cy cb
    | x == 'R' = check (cr + 1) cg cy cb && solve xs (cr + 1) cg cy cb
    | x == 'G' = check cr (cg + 1) cy cb && solve xs cr (cg + 1) cy cb
    | x == 'Y' = check cr cg (cy + 1) cb && solve xs cr cg (cy + 1) cb
    | x == 'B' = check cr cg cy (cb + 1) && solve xs cr cg cy (cb + 1)

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        print $ solve s 0 0 0 0

