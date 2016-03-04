import Control.Monad (forM_)
import Data.List

contains login [] = []
contains login (p:pass) = do
    if isPrefixOf p login
        then p
        else contains login pass

loginAttempt [] pass = []
loginAttempt login pass = do
    if p /= []
        then p : loginAttempt (drop n login) pass
        else [] where
            p = contains login pass
            n = length p

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        spass <- getLine
        login <- getLine
        let pass = words spass
            attempt = loginAttempt login pass
            res = concat attempt
        if length res == length login
            then putStrLn $ intercalate " " attempt
            else putStrLn "WRONG PASSWORD"

