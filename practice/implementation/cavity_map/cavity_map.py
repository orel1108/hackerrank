# Enter your code here. Read input from STDIN. Print output to STDOUT
def find_cavity(grid, row, col):
    max_neighbor = max(grid[row][col - 1], grid[row][col + 1], grid[row - 1][col], grid[row + 1][col])
    if grid[row][col] > max_neighbor:
        return 'X'
    return grid[row][col]

n = int(raw_input())
grid = [raw_input() for _ in range(n)]

res_grid = [['' for _ in range(n)] for __ in range(n)]
for ROW in range(n):
    res_grid[ROW][0] = grid[ROW][0]
    res_grid[ROW][n - 1] = grid[ROW][n - 1]
    
for COL in range(n):
    res_grid[0][COL] = grid[0][COL]
    res_grid[n - 1][COL] = grid[n - 1][COL]
    
for ROW in range(1, n - 1):
    for COL in range(1, n - 1):
        res_grid[ROW][COL] = find_cavity(grid, ROW, COL)
        
for ROW in res_grid:
    print ''.join(ROW)
