import qualified Data.Set as Set
import Control.Monad (forM_)

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s1 <- getLine
        s2 <- getLine
        let x = Set.fromList s1
            y = Set.fromList s2
            z = Set.intersection x y
        if Set.null z
            then putStrLn "NO"
            else putStrLn "YES"
