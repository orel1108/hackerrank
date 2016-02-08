import Control.Monad (forM_)
import Data.List
import Data.Maybe

isPalindrome s
    | and l = negate 1
    | otherwise = fromJust $ elemIndex False l where
        l = zipWith (==) s (reverse s)

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        let pos = isPalindrome s
            n = length s
        if negate 1 == isPalindrome ((take pos s) ++ (drop (pos + 1) s))
            then print $ pos
            else print $ n - pos - 1
