module Main where

process_chr :: String -> Char -> String
process_chr curr_str chr
    | length curr_str > 0 && (last curr_str == chr) = init curr_str
    | otherwise                                     = curr_str ++ [chr]

main :: IO ()
main = do
    s <- getLine
    let r = foldl (\acc chr -> process_chr acc chr) [] s
    if length r > 0
        then putStrLn r
        else putStrLn "Empty String"

