import Data.Char
import Data.Function
import Control.Monad

isFunny :: String -> Bool
isFunny =  and . (\s -> zipWith ((==) `on` abs) s (reverse s)) . (\s -> zipWith ((-)) (tail s) s) . map ord

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        if isFunny s
            then putStrLn "Funny"
            else putStrLn "Not Funny"
